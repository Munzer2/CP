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
    ll n; 
    cin >> n;
    vector< ll > a(n);
    for(auto &x : a ) cin >> x ;
    ll ans = 0;
    for(ll i = 1; i < n; ++i) {
        if(a[i] < a[i-1]) {
            ans += (a[i-1] - a[i]);
            a[i] = a[i-1];
        }
    } 
    cout << ans << "\n"; 
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