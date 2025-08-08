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
    ll n, m; 
    cin >> n >> m ;
    ll mx_mex = -1;
    for(ll i = 0 ; i < n; ++i){
        ll x ; 
        cin >> x ; 
        vector< ll > c(x); 
        ll _mex = 0;
        for(ll j = 0 ; j < x ; ++j) {
            cin >> c[j];
        }
        sort(all(c)); 
        for(ll j = 0 ; j < x; ++j) {
            if(_mex == c[j]) _mex++;
        }
        _mex++; 
        for(ll j = 0 ; j < x ; ++j){
            if(c[j] == _mex) _mex++; 
        }
        mx_mex = max( mx_mex, _mex);
    }
    ll ans = 0;
    // cout << mx_mex << "\n"; 
    if(mx_mex >=  m+1) ans =( m+1 ) *mx_mex ;
    else{
        ans += mx_mex * (mx_mex+1) ;
        ll d = mx_mex +1;
        ll terms = m - d + 1;
        ll s = (2*d + (terms-1)) * (terms) ;
        s/=2; 
        ans += s; 
    }
    cout << ans << "\n"; 
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

