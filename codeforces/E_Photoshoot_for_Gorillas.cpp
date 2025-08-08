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
    ll n , m , k ; 
    cin >> n >> m >> k;
    ll w ; 
    cin >>w ; 
    vector< ll > a(w); 
    for(auto &x : a) cin >> x; 
    sort(all(a));
    reverse(all(a));
    vector< ll > muls; 
    for(ll i = 0; i < n; ++i){
        for(ll j = 0 ; j < m; ++j){
            ll c = min(i+1,n-i);
            c = min(c,n-k+1);
            ll d = min(j+1, m - j);
            d = min(d, m-k+1);
            ll e= min(k,c)*min(k,d);
            // ll e = c*d; 
            // if(e == 15) cout << c << " " << d << "\n"; 
            muls.pb(e);
        }
    }
    sort(all(muls)); 
    reverse(all(muls));
    // debug_vector(muls);
    ll ans = 0 ; 
    for(ll i = 0 ; i < w; ++i){
        ans += (muls[i]*a[i]); 
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

////accepted.