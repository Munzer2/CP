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

void parse(ll n , ll m, ll row, ll col) {
    if(row < 0 || row > n-1 || col > m-1 || col < 0) return;
    if(vis[row][col] == 1 || a[row][col] == '#') return; 
    vis[row][col] = 1;
    parse(n,m,row+1,col);
    parse(n,m,row-1,col); 
    parse(n,m, row, col+1); 
    parse(n,m, row, col-1);
    return; 
}


void solve() {
    ll n, m ; 
    cin >> n >> m; 
    a.resize(n, vector< char >(m));
    vis.resize(n, vector< ll >(m,0)); 
    for(ll i = 0 ;i < n ; ++i) {
        for(ll j = 0 ; j < m; ++j) cin >> a[i][j];
    }
    ll ans = 0; 
    for(ll i = 0 ; i < n; ++i ) {
        for(ll j = 0; j < m ; ++j) {
            if(vis[i][j] == 0 && a[i][j] == '.') {
                ans++; 
                parse(n,m,i,j); 
            }
        }
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