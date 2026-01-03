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
vector< ll > a; 
unordered_map< ll, ll> dp;




void solve() {
    ll n ; 
    cin >> n ;
    a.resize(n);   
    for(auto &x : a) cin >> x;
    vector< ll > pre(n+1, 0), suf(n+1, 0); 
    for(ll i = 1 ; i < n ; i++ ) {
        pre[i] = pre[i-1] + abs(a[i-1]); 
    }
    for(ll i = n-1 ; i >= 0 ; i-- ) {
        suf[i] = suf[i+1] + a[i]; 
    }
    ll ans = -1*suf[1]; 
    for(ll i = 1 ; i < n ; i++ ) {
        ans = max(ans, a[0] + pre[i] - abs(a[0]) - suf[i+1]); 
    }
    cout << ans << "\n";
    a.clear(); 
   
    return; 
}

int main() {
    FAST();
    ll tt;
    cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}

/// passed all test cases