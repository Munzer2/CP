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
    ll n,k ; 
    cin >> n >> k; 
    vector< ll > b(n),a(n),c; 
    for(ll i = 0 ; i < n; ++i) { cin >> a[i]; c.pb(a[i]);  }
    for(ll i = 0 ; i < n; ++i) { cin >> b[i]; c.pb(b[i]);  }
    sort(all(a)) ; 
    sort(all(b)) ;
    sort(all(c)); 
    auto new_end = unique(all(c));
    c.erase(new_end, c.end());
    ll ans = 0;
    for(ll i = 0; i < c.size(); ++i) {
        ll cant_afford = lower_bound(all(b), c[i]) - b.begin();
        ll check = lower_bound(all(a), c[i]) - a.begin();
        if(check - cant_afford <= k) {
            ans = max(ans, (n-cant_afford)*c[i]);
        }
    }
    cout << ans << "\n"; 
    return;
}

int main() {
    ll tt;
    cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}