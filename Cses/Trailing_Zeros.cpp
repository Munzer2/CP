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
    ll i = 5; 
    ll ans = 0;
    while(i <= n) {
        ll d = (n/i); 
        ans += d ; 
        i*= 5;
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

///accepted.