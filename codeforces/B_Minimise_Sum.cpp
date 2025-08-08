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
    for(auto &x : a ) cin >> x; 
    if(a[1] == 0) { cout << a[0] << "\n" ; return ; }
    vector< ll > pre(n,0), s(n,0);
    pre[0] = a[0];
    ll ans = 1e9; 
    for( ll i = 1; i < n; ++i ) pre[i]=min(a[i], pre[i-1]);
    for(ll i = 0 ; i < n ; ++i) {
        s[i] = (!i ? pre[i] : pre[i] + s[i-1]);
    }
    // debug_vector(s); 
    // debug_vector(pre); 
    ans = s[n-1];
    for(ll i = 1 ; i < n; ++i) {
        ll d = (i-2 >= 0 ? pre[i-2] : 1e9); 
        ans = min(min(a[i] + a[i-1],d) + (i-2 >= 0 ? s[i-2]: 0), ans);
    }
    cout << ans << "\n"; 

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