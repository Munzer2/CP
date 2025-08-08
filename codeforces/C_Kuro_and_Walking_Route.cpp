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
ll Mx = 4e5+1;
vector< ll > adj[400001];
vector< ll > pars(Mx);
vector< ll > check(Mx);

void dfs(ll curr, ll targ, ll par){
    if(curr == targ) return;
    for(ll c : adj[curr]) {
        if(c != par) {
            pars[c] = curr;
            dfs(c,targ,curr);
        }
    }
    return;
}


void go(ll curr, ll &cnt,ll par) {
    if(check[curr] == -1) return;
    cnt++ ; 
    for(auto c : adj[curr]) {
        if(c != par) go(c,cnt,curr);
    }
    return ; 
}


void solve()
{
    ll n , x , y; 
    cin >> n  >> x >> y;
    for(ll i = 0 ; i < n-1; ++i) {
        ll a, b; 
        cin >> a >> b;
        adj[a].push_back(b); 
        adj[b].push_back(a);
    } 
    dfs(x,y,-1);
    ll curr = y;
    while(1) {
        check[curr] = -1;
        if(curr == x) break; 
        curr = pars[curr];
    }
    // for(ll i = 1; i <= n; ++i) cout << check[i] << " " ; 
    // cout << endl; 
    ll cnt1 = 0, cnt2 = 0 ;
    check[x] = 0; check[y] = -1;
    go(x,cnt1,-1);
    check[y] = 0; check[x] = -1;
    go(y,cnt2,-1); 
    // cout << cnt1 << " "<< cnt2 << "\n"; 
    ll ans = n*(n-1) - (cnt1*cnt2); 
    cout << ans << "\n";
    return; 
}

int main(){
    ll tt =1; 
    // cin >> tt; 
    while(tt--){
        solve() ;
    }
    return 0 ;  
}
///accepted. Good problem.