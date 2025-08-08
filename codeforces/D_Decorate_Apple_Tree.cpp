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
ll Mx = 3e5+1; 
vector< ll > adj[300005];
vector< ll > ans; 



ll dfs(ll curr, ll par) {
    if(adj[curr].size() == 1 && curr != 1) {
        ans.pb(1);
        return 1;
    }
    ll c = 0; 
    for(auto x : adj[curr]) {
        if(x == par) continue;
        c+= dfs(x,curr);
    }
    ans.pb(c); 
    return c; 
}


void solve()
{
    ll n ; 
    cin >> n ; 
    for(ll i =2; i <= n ; ++i) {
        ll x ; 
        cin >> x ; 
        adj[x].push_back(i) ; 
        adj[i].push_back(x) ;
    }
    if(n == 1) {
        cout << "1\n"; 
        return;
    }
    dfs(1,-1);
    sort(all(ans));
    debug_vector(ans);
    return;
}

int main(){
    ll tt = 1; 
    // cin >> tt;
    while(tt--){
        solve() ;
    }
    return 0 ;  
}
