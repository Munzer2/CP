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

char a[10][10]; 
ll r, c ;
ll vis[10][10]; 

void dfs(ll x, ll y, ll &cnt) { 
    if(vis[x][y]) return ; 
    vis[x][y] = 1;
    cnt++; 
    if(y+1 < c && a[x][y+1] == '#') dfs(x,y+1,cnt);
    else{
        if(x+1 < r && a[x+1][y] == '#') dfs(x+1,y,cnt); 
    }
    return;
}


void solve()
{
    cin >> r >> c ; 
    ll cnt1 = 0; 
    for(ll i = 0 ;i < r ; ++i) {
        for(ll j = 0 ; j < c; ++j) { 
            cin >> a[i][j];
            if(a[i][j] == '#') cnt1++; 
        }
    }
    if(a[0][0] != '#') {
        cout << "Impossible\n";
        return;   
    }
    ll cnt  = 0; 
    dfs(0,0,cnt);
    if(cnt == cnt1) cout << "Possible\n"; 
    else cout << "Impossible\n";
}

int main(){
    ll tt =1; 
    // cin >> tt; 
    while(tt--){
        solve() ;
    }
    return 0 ;  
}
///accepted. 
