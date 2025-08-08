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
    ll n,x,y ; 
    cin >> n >> x >> y; 
    vector< ll > a(n) ;
    ll s = 0;  
    for(auto &x : a) { cin >> x; s+=x; } 
    sort(all(a));
    ll ans = 0; 
    // debug_vector(a); 
    for(ll i = 0; i < n; ++i) {
        ll low = s - y - a[i];
        ll high = s - x - a[i];
        ll ind1 = lower_bound(a.begin() + i + 1, a.end(),low) - a.begin(); 
        ll ind2 = upper_bound(a.begin() + i + 1, a.end(),high) - a.begin();
        ans += (ind2 - ind1);
        // cout << high << " " << low << "\n"; 
        // cout << ind1 << " " << ind2 << "\n";  
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