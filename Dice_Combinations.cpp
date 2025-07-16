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

ll MOD = 1e9+7; 


void solve() {
    ll n ; 
    cin >> n ;
    vector< ll > dp(n+1, 0); 
    for(ll i = 1; i <= n ; ++i) {
        for(ll j = 1; j <= 6; ++j) {
            if(j > i ) continue;
            if(j == i) dp[i] += 1; 
            else dp[i] = (dp[i] + dp[i-j])%MOD ; 
        }
    }
    // debug_vector(dp);
    cout << dp[n] << "\n";
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll tt = 1;
    // cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}


////accepted.