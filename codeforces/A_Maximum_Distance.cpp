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
    ll n ; 
    cin >> n;
    vector< ll > a(n),b(n); 
    for(auto &c : a ) cin >> c; 
    for(auto &c : b ) cin >> c;
    ll mx = -1;
    for(ll i = 0 ; i < n-1; ++i) {
        for(ll j = i+1; j < n; ++j) {
            mx = max(mx, abs(a[i] - a[j])*abs(a[i] - a[j]) + abs(b[i] - b[j])* abs(b[i] - b[j]));
        }
    }
    cout << mx << "\n"; 
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