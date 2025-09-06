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

vector< vector< ll >> edges;
vector< ll > vis, pred;
ll strt = -1, _end = -1; 

void dfs(ll curr,ll par) {
    vis[curr] = 1; 
    pred[curr] = par; 
    for(auto &d : edges[curr]) {
        if(d == par) continue; 
        if(!vis[d]) { 
            pred[d] = curr;
            dfs(d,curr);
        }  
        else { 
            /// back edge found.
            strt = d; 
            _end = curr;
            return; 
        }
    }
    return;
}

void solve() {
    ll n,m;    
    cin >> n >> m;
    edges.resize(n+1); vis.resize(n+1,0); pred.resize(n+1,-1); 
    for(ll i = 0 ;i < m ; ++i) { 
        ll x,y; 
        cin >> x >> y; 
        edges[x].pb(y); edges[y].pb(x);
    }
    for(ll i = 1;  i<= n && strt == -1; ++i) { 
        if(!vis[i]) { 
            dfs(i,-1); 
        }
    }
    if(strt == -1) { cout << "IMPOSSIBLE\n"; }
    else { 
        vector< ll > path; 
        for(ll i = strt; ; i = pred[i]) {
            path.pb(i);
            if(i == _end) break; 
        } 
        path.pb(strt); 
        cout << path.size() << "\n"; debug_vector(path);   
    } 
    edges.clear(); vis.clear(); pred.clear(); 
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


///accepted.Find cycles in an undirected graph.