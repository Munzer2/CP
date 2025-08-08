#include<bits/stdc++.h>
#define ll long long
#define all(x) x.begin(), x.end()
#define pb(x) push_back(x)
using namespace std;


void debug_vector(vector< ll >&a){
    for(auto x : a ) cout << x  << " "  ;
    cout << "\n"; 
    return; 
}


void solve()
{
    ll n , s1, s2; 
    cin >> n >> s1 >> s2; 
    vector < pair< ll, ll > > a(n) ;
    for(ll i = 0 ; i < n; ++i){
        cin >> a[i].first; 
        a[i].second = i+1; 
    }
    sort(all(a));
    reverse(all(a));
    vector< ll > a1,b;
    ll c = s1, d = s2;
    for(ll i = 0 ; i <n; ++i){
        if(a[i].first*c < a[i].first*d){
            a1.pb(a[i].second);
            c +=s1;
        }
        else{
            b.pb(a[i].second); 
            d += s2; 
        }
    } 
    cout << a1.size() << " "; debug_vector(a1); 
    cout << b.size() << " "; debug_vector(b);
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
///accepted.