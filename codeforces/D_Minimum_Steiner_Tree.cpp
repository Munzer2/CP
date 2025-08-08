#include<bits/stdc++.h>
#define ll long long
#define all(x) x.begin(), x.end()
#define pb(x)  push_back(x)
using namespace std;
 
vector< ll > edges[2<<17];
vector <ll > vis(2<<17,0);
vector< ll > check(3e5+1,0);

void debug_vector(vector< ll >&a){
    for(auto x : a ) cout << x  << " "  ;
    cout << "\n"; 
    return; 
}




// bool go(ll curr, ll par,ll &ans){
//     bool ok = (ns.count(curr));
//     for(auto c : edges[curr]){
//         if(c == par) continue;
//         if(go(c,curr,ans)) ok = true;
//     }
//     if(ok) ans++;
//     return ok;
// }



ll go2(ll curr,ll &ans){
    ll ok = 0;
    vis[curr] = 1;
    if(check[curr]) ok = 1;
    for(auto x: edges[curr]){
        if(vis[x]) continue;
        if(go2(x,ans)) ok = 1; 
    }
    if(ok) ans++;
    return ok;
}

// void solve()
// {
//     ll N, K; 
//     cin >> N >> K;
//     for(ll i = 0 ; i < N-1; ++i){
//         ll x, y ; 
//         cin >> x >> y; 
//         edges[x].pb(y); 
//         edges[y].pb(x);
//     }
//     ll curr; 
//     for(ll i = 0 ; i < K ; ++i) {
//         ll x ; 
//         cin >> x; 
//         if(!i) curr = x;
//         ns.insert(x);
//     }
//     ll ans = 0;
//     go(curr, -1,ans);
//     cout << ans << "\n";  
//     return; 
// }


void solve2(){
    ll N, K; 
    cin >> N >> K;
    for(ll i = 0 ; i < N-1; ++i){
        ll x, y ; 
        cin >> x >> y; 
        edges[x].pb(y); 
        edges[y].pb(x);
    }
    ll curr; 
    for(ll i = 0 ; i < K ; ++i) {
        ll x ; 
        cin >> x; 
        if(!i) curr = x;
        check[x] = 1;
    }
    ll ans = 0;
    go2(curr,ans);
    cout << ans << "\n";  
    return; 
}

int main(){
    ios::sync_with_stdio(false);
	cin.tie(nullptr);
    
    ll tt =1; 
    // cin >> tt; 
    while(tt--){
        // solve() ;
        solve2();
    }
    return 0 ;  
}


///accepted. take-away: dont use big stuffs as paramters in dfs function!