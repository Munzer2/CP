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
    cin >> n ; 
    if(n == 1) {
        cout << "-1\n"; 
        return;
    }
    vector< ll > ans(n);
    for(ll i = 0; i < n; ++i) ans[i] = i+1;
    ll d = n*(n+1)/2;
    ll c = sqrt(d);
    if(c *c == d) {
        cout << "-1\n"; 
        return;
    }
    for(ll i =0 ; i < n-1; ++i) {
        ll d = (i+1)*(i+2)/2;
        ll c = sqrt(d);
        if(c*c == d) swap(ans[i], ans[i+1]); 
    }
    debug_vector(ans); 
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll tt;
    cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}