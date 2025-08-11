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
    vector< ll > a(n); 
    for(auto &x : a ) cin >> x; 
    vector< ll > pos(n+1, 0);
    map< ll, ll > ind, cnt;
    for(ll i = 0 ; i < n; ++i) {
        cnt[a[i]]++;
        if(cnt[a[i]] > 1) {
            pos[i+1] = max(ind[a[i]]+1, pos[i]);
        }
        else {
            pos[i+1] = pos[i];     
        }
        ind[a[i]] = i ; 
    }
    /// Check the pos vector.
    // for(ll i = 1;  i<= n ; ++i) cout << pos[i] << " "; 
    // cout << endl;
    ll ans = 0;  
    for(ll i = 1; i <= n; ++i) {
        ll len = (i-pos[i]);
        ans += len;
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

//// accepted