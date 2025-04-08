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
    cin >> n ;
    vector< ll > a(n); 
    for(auto &x : a ) { cin >> x; }
    sort(all(a));  
    ll s = a[n/2];
    s = (n%2 ? s : (s+a[n/2 -1])/2);
    ll ans = 0; 
    for(auto x : a ) ans += abs(s-x); 
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