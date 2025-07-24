#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#define ll long long
#define all(x) x.begin(), x.end()
#define pb(x) push_back(x)
using namespace std;

void debug_vector(vector<ll>& a) {
    for (auto x : a) cout << x << " ";
    cout << "\n";
    return;
}

vector< vector< ll >> edges; 
map< ll, ll > red, black; 
vector< ll > vis; 
bool ok = true; 


void dfs(ll curr, ll ind) {
    if(vis[curr]) {
        ok &= (!ind && red[curr]) || (ind && black[curr]) ; 
        return; 
    } 
    vis[curr] = 1;
    if(!ind) red[curr] = 1;
    else black[curr] = 1;
    for(auto c : edges[curr]) dfs(c, (ind+1)%2); 
    return; 
}

void solve() {
    ll n , m ; 
    cin >> n >> m;
    edges.resize(n+1);
    vis.resize(n+1,0);    
    for(ll i = 0 ; i < m; ++i) {
        ll x , y; 
        cin >> x >> y;
        edges[x].pb(y) ; edges[y].pb(x); 
    }
    ll ind = 0 ; 
    for(ll i = 1; i <= n; ++i ) {
        if(!vis[i]) dfs(i, ind); 
    } 
    if(!ok) {
        cout << "IMPOSSIBLE\n"; return; 
    } 
    for(ll i = 1; i <= n; ++i) {
        cout << (red[i] ? "1 " : "2 "); 
    }
    cout << "\n"; 
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


//accepted.