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
    ll n , m ; 
    cin >> n >> m; 
    vector< ll > a(n); 
    ll mx = -1; 
    for(auto &x : a) { 
        cin >> x; mx = max(mx, x); 
    } 

    vector< vector < ll >> dp(n+1,vector< ll >(mx+3,1)); 
    for(ll i = 0; i < n; ++i) {
        if(a[i-1] != 0) continue;
        for(ll j = 1; j <= mx+2 ; ++j) {
            
        }
    }
    return;
}

/// dp[i][v] = number of ways to fill up positions 0...i and A[i] becomes v.


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll tt;
    cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}