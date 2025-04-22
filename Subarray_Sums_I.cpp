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
    ll n , x ; 
    cin >> n >> x ; 
    vector< ll > a(n); 
    for(auto &x: a ) cin >> x;
    vector< ll > pre(n+1,0);
    map< ll, ll > mp; 
    for(ll i = 1; i <= n; ++i) {
        pre[i] = pre[i-1] +  a[i-1];
        mp[pre[i]] = i;
    }
    ll ans = 0; 
    for(ll i = 1; i <= n; ++i) {
        if(pre[i] < x ) continue;
        if(pre[i] == x) {
            ans++; 
        }
        else {
            if(mp[pre[i]-x] < i && mp[pre[i]-x] > 0) {
                ans++; 
            }
        }
    }
    // debug_vector(pre); 
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

///accepted. Nice problem.