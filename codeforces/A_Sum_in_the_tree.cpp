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
vector< ll > adj[300001];
vector< ll > a(Mx);

void dfs(ll curr,ll sum,ll &ans,bool &ok,ll par) {
    if(a[curr] == -1) {
        ll mn = 1e15;
        for(auto c : adj[curr]) {
            if(c != par ) mn = min(mn,a[c]);
        }
        if(mn == 1e15) {
            return;
        }
        if(mn < sum) {
            ok = false; 
            return ; 
        }
        ans += mn - sum;
        for(auto c : adj[curr ] ) {
            if(c != par ) dfs(c,mn,ans,ok,curr); 
        }
    }
    else{
        ans += a[curr] - sum;
        for(auto c : adj[curr]) {
            if(c != par) {
                dfs(c, a[curr], ans,ok , curr);
            }
        }
    }
    return ; 
}

void solve()
{
    ll n ; 
    cin >> n ;
    for(ll i = 2 ;i <= n; ++i) {
        ll x; 
        cin >> x; 
        adj[x].push_back(i) ; 
        adj[i].push_back(x);
    }
    for(ll i = 1 ; i <= n; ++i) cin >> a[i];  
    bool ok = true; 
    ll ans = 0;
    dfs(1,0,ans,ok,-1) ; 
    if(ok) cout << ans << "\n" ; 
    else cout << "-1\n"; 
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