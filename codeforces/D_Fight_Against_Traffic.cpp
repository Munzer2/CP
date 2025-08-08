#include<bits/stdc++.h>
#define ll long long
#define all(x) x.begin(), x.end()
#define pb(x)  push_back(x)
using namespace std;


void debug_vector(vector< ll >&a){
    for(auto x : a ) cout << x  << " "  ;
    cout << "\n"; 
    return; 
} 

ll Mx = 3e4+1; 
vector< ll > adj[30005];
vector< ll > dist(Mx,1e9);
vector< ll > dist2(Mx,1e9);
ll Edges[3005][3005]; 

void bfs(ll src) {
    queue< ll > q;
    q.push(src);
    dist[src] = 0;
    while(!q.empty()){
        ll curr = q.front(); 
        q.pop(); 
        for(auto x : adj[curr]) {
            if(dist[x] == 1e9) {
                dist[x] = dist[curr] + 1;  
                q.push(x);
            }
        }
    }
    return; 
}


void bfs2(ll src) {
    queue< ll > q;
    q.push(src);
    dist2[src] = 0;
    while(!q.empty()){
        ll curr = q.front(); 
        q.pop(); 
        for(auto x : adj[curr]) {
            if(dist2[x] == 1e9) {
                dist2[x] = dist2[curr] + 1; 
                q.push(x);
            }
        }
    }
    return; 
}


void solve()
{
    ll n , m , s , t; 
    cin >> n >> m >> s >> t;
    
    for(ll i = 0 ; i < m; ++i) {
        ll x , y ; 
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
        Edges[x][y] = 1;
        Edges[y][x] = 1;
    }
    bfs(s);
    bfs2(t);
    ll mn = dist[t];
    ll ans= 0 ;
    // cout << mn << "\n";
    for(ll i = 1; i <= n; ++i) {
        for(ll j = 1; j <= n; ++j) {
            if(i == j || Edges[i][j]) continue;
            // cout << dist[i] + dist2[j] + 1 << "\n"; 
            if(dist[i] + dist2[j]+1 >= mn && dist[j] + dist2[i]+1 >= mn) {
                ans++ ; 
                Edges[i][j] = 1; 
                Edges[j][i] = 1;
            }
        }
    }
    cout << ans << "\n";
    return;
}

int main(){
    ll tt = 1; 
    // cin >> tt;
    while(tt--){
        solve();
    }
    return 0 ;  
}
///accepted.
