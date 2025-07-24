#include<bits/stdc++.h>
#define ll long long
#define all(x) x.begin(), x.end()
#define pb(x) push_back(x)
using namespace std;

void debug_vector(vector<int>& a) {
    for (auto x : a) cout << x << " ";
    cout << "\n";
    return;
}


int MOD = 1e9 + 7; 

void solve() {
    int n , x ; 
    cin >> n >> x ;
    vector< int > a(n), dp(x+1, 0); 
    for(auto &x : a ) cin >> x ;  
    dp[0] = 1;
    sort(all(a)); 
    for(int c = 0 ; c < n; ++c) {
        int d = a[c];  
        for(int p = d ; p<= x; ++p) {
            dp[p] += dp[p - d]; 
            if(dp[p] >= MOD) dp[p] -= MOD; 
        }
    }
    // debug_vector(dp); 
    cout << dp[x] << "\n"; 
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