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

void solve() {
    ll n, q ; 
    cin >> n >> q ; 
    vector< ll > a(n) ; 
    for(auto &x : a ) cin >> x;
    vector< ll > pre(n+1, 0);
    pre[0] = a[0];
    for(ll i = 1 ; i < n; ++i) {
        pre[i] = pre[i-1] ^ a[i];
    } 
    while(q--) {
        ll x  , y; 
        cin >> x >> y; 
        --x; --y; 
        ll left = ( x == 0 ? 0 : pre[x-1]); 
        ll right = pre[n-1] ^ pre[y];
        cout << (left ^ right ^ pre[n-1]) << "\n"; 
    }
    return;
}

int main() {
    ll tt = 1;
    // cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}