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

vector< ll > a;
vector< ll > vis; 
vector< ll > ans;
string s; 


void dfs(ll curr, ll &cnt, ll &tot){
    if(vis[curr]) return;
    vis[curr] = 1;
    if(s[curr-1] == '0') cnt++; 
    tot++;
    dfs(a[curr],cnt,tot);
    return; 
}

void dfs2(ll curr, ll _ans, ll tot, ll &curr_s){
    ans[curr] = _ans;
    curr_s++; 
    if(curr_s == tot) return;
    dfs2(a[curr], _ans, tot,curr_s);
    return;
}



void solve()
{
    ll n ; 
    cin >> n;
    a.resize(n+1);
    vis.resize(n+1);
    ans.resize(n+1);
    for(ll i = 1; i <= n; ++i) cin >> a[i]; 
    cin >> s;
    for(ll i = 1; i <= n ; ++i) {
        if(!vis[a[i]]) {
            ll cnt = 0, tot = 0;
            dfs(a[i],cnt,tot);
            ll curr_s = 0;
            dfs2(a[i],cnt,tot,curr_s);
        }
        cout << ans[a[i]] << " "; 
    } 
    cout << endl; 
    a.clear();
    vis.clear(); 
    ans.clear();  
    return; 
}

int main(){
    ll tt; 
    cin >> tt;
    while(tt--){
        solve() ;
    }
    return 0 ;  
}
