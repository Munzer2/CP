#include<bits/stdc++.h>
#define ll long long
#define all(x) x.begin(), x.end()
#define pb(x) push_back(x)
#define FAST() ios::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

void debug_vector(vector<ll>& a) {
    for (auto x : a) cout << x << " ";
    cout << "\n";
    return;
}

ll MOD = 1e9 + 7;

void solve() {
    ll n , m ; 
    cin >> n >> m; 
    vector< ll > a(n); 
    for(auto &x : a) { 
        cin >> x;
    } 
    vector< vector< ll >> dp(n, vector< ll >(m+1,0));
    for(ll i = 1; i <= m ; ++i) { 
        dp[0][i] = (a[0] == 0 ? 1 : (i == a[0] ? 1 : 0));
    }
    for(ll i = 1 ; i < n; ++i) { 
        if(a[i] != 0) { 
            for(ll val = max(1LL,a[i]-1);  val <= min(m,a[i]+1); ++val) dp[i][a[i]] = (dp[i][a[i]] + dp[i-1][val])%MOD;
            continue ; 
        }
        for(ll p = 1; p <= m; ++p) { 
            for(ll val = max(p-1,1LL) ; val <= min(m,p+1); ++val) dp[i][p] = (dp[i][p] + dp[i-1][val])%MOD;
        }
    }
    ll ans = 0; 
    for(ll p = 1; p <= m ; ++p) ans = (ans + dp[n-1][p])%MOD;
    cout << ans << "\n";  
    return;
}

/// dp[i][v] = number of ways to fill up positions 0...i and A[i] becomes v.

int main() {
    FAST();
    ll tt = 1;
    // cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}