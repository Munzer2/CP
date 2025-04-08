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
    vector< vector< ll >> a(n,vector< ll >(2));
    vector< ll > s,e; 
    for(ll i = 0; i < n; ++i) {
        cin >> a[i][0] >> a[i][1]; 
        s.pb(a[i][0]); 
        e.pb(a[i][1]); 
    }
    sort(all(s)); 
    sort(all(e)); 
    ll ans = 0;
    for(ll i = 0; i < n; ++i) {
        for(ll j = 0 ;j < 2; ++j) {
            ll num = a[i][j];
            ll ind1 = lower_bound(all(e),num) - e.begin();
            ll ind2 = lower_bound(all(s), num + 1) - s.begin(); 
            ind2 =  n - ind2;
            ans = max(ans, n - ind1 - ind2);
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


///accepted.