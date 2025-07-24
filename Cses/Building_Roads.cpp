#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long
#define all(x) x.begin(), x.end()
#define pb(x) push_back(x)
using namespace std;

vector< vector< ll >> edges;


void debug_vector(vector<ll>& a) {
    for (auto x : a) cout << x << " ";
    cout << "\n";
    return;
}
vector< ll > vis;

void dfs(ll curr) {
    if(vis[curr]) return;
    vis[curr] = 1;
    for(auto c : edges[curr]) dfs(c); 
    return; 
}


void solve() {
    ll n, m ; 
    cin >> n >> m; 
    edges.resize(n+1); 
    vector< ll > conn;
    for(ll i = 0 ;i < m; ++i) {
        ll x , y ; 
        cin >> x >> y ; 
        edges[x].pb(y); 
        edges[y].pb(x);
    }
    vis.resize(n+1,0);
    dfs(1); 
    conn.pb(1); 
    ll cnt = 1;  
    for(ll i = 2; i <= n; ++i) {
        if(!vis[i]) {
            dfs(i); 
            cnt++;
            conn.pb(i);  
        }
    }
    cout << cnt-1 << "\n";
    for(ll i = 0 ; i < conn.size() - 1; ++i) cout << conn[i] << " " << conn[i+1] << "\n"; 
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