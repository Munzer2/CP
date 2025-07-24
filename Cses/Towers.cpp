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
    cin>> n ; 
    vector< ll > a(n); 
    for(ll i = 0 ; i < n; ++i) cin >> a[i];
    vector< ll > curr;
    ll ans = 1; 
    curr.pb(a[0]);
    for(ll i =1 ; i < n; ++i) {
        ll ind = upper_bound(all(curr),a[i]) - curr.begin();
        if(ind == curr.size()) {
            curr.pb(a[i]);
            ans++;
        }
        else {
            curr[ind] = a[i]; 
        }
        // debug_vector(curr);
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