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


ll check(ll k, ll mid, ll n) {
    ll c = k+n-1 - mid;
    ll plus = mid -k + 1 - c;
    c = c*c;
    ll sum = (2*k +  (plus-1))*plus;
    sum /=2;
    ll _ans = abs(c-sum) ;
    return _ans; 
}

void solve()
{
    ll n , k ; 
    cin >> n >> k;
    ll d = (n%2 ? (n-1)/2  : n/2);
    ll low = k+d-1;
    d=  (n%2 ? d + k : d);
    ll high = k+n-1;
    while(low < high) {
        ll mid = (low + high)>>1; 
        ll _ans = check(k,mid,n); 
        if(d >= _ans) {
            d = _ans;
            low = mid+1;
        }
        else{
            high = mid;
        }
    }
    ll check1 = check(k,low,n);
    d = min(d, check1);
    cout << d << "\n"; 
    return;  
}

int main(){
    ll tt; 
    cin >> tt;
    while(tt--){
        solve() ;
    }
    return 0 ;  
}
