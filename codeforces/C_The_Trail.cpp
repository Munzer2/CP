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
    ll n, m ; 
    cin >> n >> m; 
    string s ; 
    cin >> s; 
    vector< vector< ll >> a(n, vector< ll >(m,0)); 
    for(ll i =0; i < n; ++i) {
        for(ll j = 0 ;j < m; ++j) cin >> a[i][j];
    }
    vector< vector< ll > > vis(n,vector< ll >(m,0));
    ll x = 0, y =0;
    vis[x][y] = 1;
    for(ll i = 0; i < s.size(); ++i) {
        if(s[i] == 'R') y++;
        else x++;
        vis[x][y] = 1;
    }
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