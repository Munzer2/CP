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
    ll n ; 
    cin >> n;
    ll a[n][n][n];
    for(ll i = 0 ; i < n; ++i){
        for(ll j = 0 ; j < n ; ++j){
            for(ll k = 0 ; k < n; ++k) cin >> a[i][j][k];
        }
    }

    ll pre[n][n][n], pre1[n][n][n]; 
    for(ll i = 0 ; i < n; ++i){
        for(ll j = 0 ; j < n ; ++j){
            for(ll k = 0 ; k < n; ++k) {
                if(!k ) pre[i][j][0] = a[i][j][0]; 
                else pre[i][j][k] = pre[i][j][k-1] + a[i][j][k];
            }
        }
    }
    for(ll i = 0 ; i < n; ++i){
        for(ll j = 0 ; j < n ; ++j){
            for(ll k = 0 ; k < n; ++k)[
                pre1[i][j][]
            ]
        }
    }
    // for(ll i = 0 ; i < n; ++i){
    //     for(ll j = 0 ; j < n; ++j){
    //         for(ll k = 0 ; k < n; ++k) cout << pre[i][j][k] << ' '; 
    //     }
    // }

    ll q; 
    cin >> q; 
    while(q--){
        ll lx,rx,ly,ry,lz,rz; 
        cin >> lx >> rx >> ly >> ry >> lz >> rz;
        lz--; rz--;
        ll ans = 0;
        for(ll i = lx-1; i <= rx-1; ++i){
            for(ll j = ly-1; j <= ry-1; ++j){
                if(!lz) ans += pre[i][j][rz];
                else ans += (pre[i][j][rz] - pre[i][j][lz-1]);
            }
        }
        cout << ans << "\n";
    }
    return;  
}

int main(){
    ll tt = 1; 
    // cin >> tt; 
    while(tt--){
        solve() ;
    }
    return 0 ;  
}