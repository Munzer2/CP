#include<bits/stdc++.h>
#define ll long long
#define all(x) x.begin(), x.end()
#define pb(x) push_back(x)
using namespace std;


void printVect(vector< ll > a) { 
    for(auto x : a) cout << x << " "; 
    cout << "\n";
    return;
}


void solve() {
    ll n; 
    cin >> n; 
    vector< ll > a(n);
    for(auto &x : a ) cin >> x;
    vector< vector< ll > > pos(n+1);
    for(ll i = 0; i < n; ++i) { 
        pos[a[i]].pb(i);
    }
    vector< ll > dp(n,0);  
    for(ll i = 0 ; i < n ; ++i) { 
        dp[i] = (i ? dp[i-1] : 0); 
        auto &p = pos[a[i]];
        ll ind = lower_bound(all(p),i) - p.begin(); 
        // cout << "value: " << a[i] << " " << ind << "\n";
        if(ind+1 < a[i]) continue;
        ll check = p[ind - a[i] + 1]; 
        dp[i] = max(dp[i], (check > 0 ? dp[check-1] : 0) + a[i]);    
    } 
    // for(auto &x : dp) cout << x << " " ; 
    // cout << "\n";
    cout << dp.back() << "\n"; 
    return;
}

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


///accepted. 