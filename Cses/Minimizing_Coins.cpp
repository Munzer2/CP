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

ll INF = 1e9;


void solve() {
    ll n, x ; 
    cin >> n >> x; 
    vector< ll > a(n); 
    for(auto &x : a ) cin >> x; 
    sort(all(a)); 
    vector< ll > dp(x+1, INF); 
    for(ll i = 1; i <= x ; ++i) {
        for(ll j = 0 ; j < n; ++j) {
            if(a[j] > i) continue;
            if(a[j] == i) dp[i] = 1; 
            else dp[i] = min(dp[i],  dp[i-a[j]] + 1);
        }
    }
    cout << (dp[x] == INF ? -1 : dp[x]) << "\n"; 
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

///accepted.