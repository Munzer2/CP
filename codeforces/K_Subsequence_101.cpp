#include<bits/stdc++.h>
#define ll long long
#define all(x) x.begin(), x.end()
#define pb(x)  push_back(x)
using namespace std;


void debug_vector(vector< ll >&a){
    for(auto x : a ) cout << x  << " "  ;
    cout << "\n"; 
    return; 
}


void solve()
{
    ll n , k ; 
    cin >> n >> k ;
    vector< ll > a(n);
    for(auto &x : a ) cin >> x;
    if(k == 2){
        sort(all(a)); 
        cout << a[n-1] + a[n-2] << "\n";
        return; 
    }
    priority_queue< pair< ll, ll> , vector<pair< ll, ll >>, greater<pair< ll, ll>>> pq;  
    for(ll i = 1; i <= n-2; ++i){
        pq.push({a[i],i});
        if(pq.size() > k-2) pq.pop();
    }
    ll s = 0, left = -1, right  = -1;
    while(!pq.empty()){
        pair< ll , ll > x = pq.top();
        ll ind = x.second;
        left = (left == -1 ? ind: (ind < left ? ind : left));
        right = (right == -1 ?  ind: (ind > right? ind: right));
        s += (x.first);
        pq.pop();
    }
    s *= 2;
    // cout << left << "\n"; 
    ll d = *max_element(a.begin(), a.begin() + left) ;
    ll e = *max_element(a.begin() + right+1,a.end());
    cout << s  + d + e  << "\n"; 
    return;  
}

int main(){
    ll tt ; 
    cin >> tt; 
    while(tt--){
        solve() ;
    }
    return 0 ;  
}