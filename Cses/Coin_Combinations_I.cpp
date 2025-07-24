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
    int n,x; 
    cin >> n >> x;
    vector< ll > a(n); 
    for(auto &x : a ) cin >> x; 
    vector< int > dp(x+1, 0);
    dp[0] = 1;
    sort(all(a));  
    for(ll i = 1; i <= x ; ++i) {
        int s = 0;
        for(ll j = 0 ; j < n; ++j) {
            if(a[j] > i ) break;
            s += dp[i- a[j]];
            if(s >= MOD) s-= MOD ;
        }
        dp[i] = s;
    }
    cout << dp[x] << "\n"; 
    return;
} 
//// ------> accepted. Using s -= MOD instead of % and also using a temp var s instead of dp[i] each iteration. 

void solve2() {
    int n,x; 
    cin >> n >> x;
    vector< ll > a(n); 
    for(auto &x : a ) cin >> x; 
    vector< int > dp(x+1, 0);
    dp[0] = 1;
    sort(all(a));  
    for(ll i = 1; i <= x ; ++i) {
        for(ll j = 0 ; j < n; ++j) {
            if(a[j] > i ) break;
            dp[i] += dp[i- a[j]];
            if(dp[i] >= MOD) dp[i]-= MOD ;
        }
    }
    cout << dp[x] << "\n"; 
    return;
}
///// -----> also accepted. Just using dp[i] -= MOD instead of %. No extra temp var.

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll tt = 1;
    // cin >> tt;
    while (tt--) {
        solve2();
    }
    return 0;
}