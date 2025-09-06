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
    ll n ,x ; 
    cin >> n >> x; 
    map< ll, vector< ll >> mp;
    vector< ll > pre(n,0);
    mp[0].pb(-1); 
    for(ll i = 0 ; i< n; ++i) {
        ll _x; 
        cin >>  _x ;  
        pre[i] = (!i ? 0 : pre[i-1]) + _x;
        mp[pre[i]].pb(i);
    }
    ll cnt = 0; 
    auto get_cnt = [&](vector< ll > &vec, ll val) -> ll { 
        return upper_bound(all(vec),val) - vec.begin(); 
    };
    for(ll i = 0 ; i < n; ++i) { 
        if(mp.count(pre[i]-x)) { 
            auto &v = mp[pre[i]-x];  
            cnt += get_cnt(v, i-1);
        } 
    }
    cout << cnt << "\n";
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


///accepted. A nice way to count all subarrays with the sum of x.