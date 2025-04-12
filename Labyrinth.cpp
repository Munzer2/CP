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
 
vector< vector< char >> a;
vector< vector< ll >> vis;
 
void bfs(pair< ll, ll > strt, pair< ll, ll > end, ll &_ok) {
    ll n = a.size(), m = a[0].size(); 
    queue< pair< ll, ll >> q;
    q.push(strt);
    vector< vector< ll >> dist(n, vector< ll >(m, -1));
    vector< vector< pair< ll, ll >>> par(n, vector< pair< ll, ll >>(m, {-1,-1})) ; 
    dist[strt.first][strt.second] = 0;
    while(!q.empty()) {
        pair< ll, ll > node = q.front();
        q.pop(); 
        ll r = node.first, c = node.second; 
        if(a[r][c] == 'B') {
            _ok = 1; 
            cout << "YES\n"; 
            cout << dist[r][c] << "\n";
            vector< char > ans;
            while(a[r][c] != 'A') {
                pair< ll, ll > _p = par[r][c];
                if(_p.first < r) ans.pb('D'); 
                else if(_p.first > r) ans.pb('U'); 
                else if(_p.second < c) ans.pb('R'); 
                else if(_p.second > c) ans.pb('L');
                r = _p.first;
                c = _p.second;    
            }
            reverse(all(ans));
            for(auto x : ans ) cout << x; 
            cout << "\n";  
            return;
        }
        vector< pair< ll, ll >> dir = {{-1,0}, {1,0}, {0,1}, {0,-1}};
        for(auto d : dir) {
            ll _r = r + d.first, _c = c + d.second;
            if(_r >= 0 && _r < n && _c >= 0 && _c < m && a[_r][_c] != '#' && vis[_r][_c] == 0) {
                vis[_r][_c] = 1; 
                dist[_r][_c] = dist[r][c] + 1; 
                par[_r][_c] = {r,c}; 
                q.push({_r,_c}); 
            }
        }
    }
    return; 
}
 
 
void solve() {
    ll n, m ; 
    cin >> n >> m; 
    a.resize(n, vector< char >(m));
    vis.resize(n, vector< ll >(m,0));
    pair< ll, ll > strt, end;  
    for(ll i = 0 ;i < n ; ++i) {
        for(ll j = 0 ; j < m; ++j) {
            cin >> a[i][j];
            if(a[i][j] == 'A') strt = {i,j}; 
            else if(a[i][j] == 'B') end = {i,j}; 
        }
    }
    ll _ok = 0;
    bfs(strt,end, _ok);
    if(!_ok) {
        cout << "NO\n"; 
    } 
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
