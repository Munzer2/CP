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
    vector< ll > pre(n,0);
    map<ll ,vector< ll >> mp;
    mp[0].pb(-1);  
    for(ll i = 0; i < n; ++i){ 
        ll x ; cin >> x; 
        pre[i] = (!i?0:pre[i-1]) + x;
        ll r = ((pre[i]%n) + n)%n;
        mp[r].pb(i); 
    }
    // debug_vector(pre);
    ll ans = 0; 
    for(auto &x : mp) { 
        ll sz = x.second.size(); 
        if(sz <= 1) continue;
        ans += (sz*(sz-1))/2; 
    }
    cout << ans << "\n";
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll tt=1;
    // cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}


///accepted.