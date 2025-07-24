#include<bits/stdc++.h>
#define ll long long
#define all(x) x.begin(), x.end()
#define pb(x) push_back(x)
using namespace std;

void debug_vector(vector<ll>& a) {
    for (auto x : a) cout << x << " ";
    cout << "\n";
    return;
}

ll MOD = 1e9 + 7;

void solve() {
    ll n ;
    cin >> n ; 
    ll ans = 0;
    ll d = 1;  
    while(d <= n ) {
        ll q = n/d;
        ll r = n/q; 
        ll cnt = (r-d+1);
        __int128_t sum =(__int128_t)(d+r) * cnt / 2; 
        ll sumd = (ll) (sum%MOD); 
        ans = ( ans + ((q%MOD)*(sumd))%MOD)%MOD;  
        d = r+1;  
    }
    cout << ans << "\n"; 
    return;
}


//// ans is 1.[n] + 2.[n/2] + ... 

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll tt=1;
    // cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}


////Really good problem. Main idea is that there are almost 2*sqrt(n) distinct values that [n/d] can take.