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

vector< vector < pair< ll, ll >>> edges;

void solve() {
    ll n, m ; 
    cin >> n >> m ; 
    edges.resize(n+1); 
    for(ll i = 0 ;i < m ; i++) {
        ll u, v, w; 
        cin >> u >> v >> w; 
        edges[u].push_back({v,w});
    }
    priority_queue< vector< ll >, vector< vector< ll >>, greater< vector< ll >>> pq; // Min-Heap
    pq.push({0,1});
    vector< ll > _dist(n+1, LLONG_MAX);
    _dist[1] = 0;

    while(!pq.empty()) {
        ll  u = pq.top()[1];
        ll d = pq.top()[0];
        
        pq.pop(); 

        if(_dist[u] < d) continue;
        for(auto x: edges[u]) {
            ll v = x.first;
            if(_dist[u] != LLONG_MAX &&  _dist[v] > _dist[u] + x.second) {
                _dist[v] = _dist[u] + x.second;
                pq.push({_dist[v], v});
            }
        } 
    }

    for(ll i = 1; i <= n; i++) {
        cout << _dist[i] << " ";
    }
    cout << "\n";
    edges.clear(); 
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


////accepted.