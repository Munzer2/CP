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
    ll n , q; 
    cin >> n >> q;
    vector< ll > a(n), pre(n,0); 
    for(ll i = 0 ; i < n; ++i) {
        cin >> a[i]; 
        pre[i] = (i == 0 ? a[i] : pre[i-1] + a[i]);
    }

    while(q--) {
        ll x, y; 
        cin >> x >> y; 
        x--; 
        y--; 
        cout << pre[n-1] - (pre[n-1] - pre[y] + (x == 0 ? 0 :  pre[x-1])) << "\n";   
    }
    return;
}

int main() {
    ll tt=1;
    // cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}