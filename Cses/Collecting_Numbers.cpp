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


void solve()
{
    ll n ; 
    cin >> n ;
    map< ll , ll > ind; 
    ll ans = 1;
    for(ll i = 0; i <n; ++i){
        ll x ; 
        cin >> x; 
        ind[x] = i;
    }
    ll curr = ind[1];
    for(ll i = 2; i <= n; ++i){
        if(ind[i] < curr) { 
            ans++;
        } 
        curr = ind[i];
    }
    cout << ans << "\n"; 
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