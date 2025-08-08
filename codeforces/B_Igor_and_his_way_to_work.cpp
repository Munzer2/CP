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

vector< vector< char >> a;
bool ok = false; 

void dfs(ll x, ll y,ll turns, pair< ll, ll > dir) {
    ll r = a.size(), c = a[0].size();
    if(x < 0 || y < 0 || x >= r || y >= c) return;
    if(turns > 2 || a[x][y] == '*') return;
    if(a[x][y] == 'T') {
        ok = true; 
        return;
    }
    vector< pair< ll, ll>> moves = {{-1,0}, {1,0}, {0,1} , {0,-1}};
    for(auto d : moves) {
        if(d.first == dir.first && d.second == dir.second) dfs(x + d.first, y+ d.second,turns,d); 
        else dfs(x+d.first, y+d.second,turns+1,d);
    }
    return;
}

void solve()
{
    ll n,m ; 
    cin >> n >> m ;
    pair< ll, ll > strt; 
    a.resize(n,vector< char >(m));
    for(ll i = 0 ; i < n; ++i) {
        for(ll j = 0 ; j< m; ++j) {
            cin >> a[i][j];
            if(a[i][j] == 'S') { strt.first = i; strt.second = j; }
        }
    }
    dfs(strt.first, strt.second, -1, {-1,-1});
    cout << (ok ? "YES" : "NO") << "\n"; 
    return;
}

int main(){
    ll tt  = 1; 
    // cin >> tt; 
    while(tt--){
        solve() ;
    }
    return 0 ;  
}