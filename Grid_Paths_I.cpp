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
    ll n; 
    cin >> n ; 
    vector< vector< char >> grid(n, vector< char >(n)); 
    vector< vector< ll > > dp(n,vector< ll >(n,0));
    for(ll i = 0; i < n ; ++i ) {
        for(ll j = 0;  j< n; ++j) cin >> grid[i][j];
    }
    dp[0][0] = (grid[0][0] == '*' ? 0 : 1);
    for( ll i = 0 ; i < n ; ++i ) {
        for(ll j = 0 ; j < n ; ++j) {
            if(grid[i][j] == '*') continue;
            ll c1 = 1, c2 = 1;
            c1 &= (i-1>= 0) ; c2 &=(j-1>=0);
            if(c1) {
                dp[i][j] = (dp[i][j] + (grid[i-1][j] == '*' ? 0 : dp[i-1][j]))%MOD;
            }
            if(c2) {
                dp[i][j] = (dp[i][j] + (grid[i][j-1] == '*' ? 0 : dp[i][j-1]))%MOD;
            }
        } 
    }

    cout << dp[n-1][n-1] << "\n"; 
    return;
}

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


///accepted. A nice corner case when 1by1 grid has * only then 
///dp[0][0] should be 0.