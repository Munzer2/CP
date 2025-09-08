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
    ll n ; cin >> n ; 
    vector< ll > a(n);
    map< ll, vector< ll >> mp;
    for(ll i = 0 ; i < n; ++i) { 
        cin >> a[i];
        mp[a[i]].pb(i); 
    }
    bool ok= true; 
    for(auto &x : mp) {
        if((ll)x.second.size() % (ll)x.first != 0) {
            ok &= false; break; 
        } 
    }
    if(!ok) {  cout << "-1\n"; return; }
    ll curr = 1;
    vector< ll > ans(n); 
    for(auto &x : mp) { 
        for(ll i = 1; i <= x.second.size(); ++i) { 
            ans[x.second[i-1]] = curr; 
            if(i%x.first == 0) curr++;
        }
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