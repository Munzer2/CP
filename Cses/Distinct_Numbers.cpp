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
    cin >> n; 
    set< ll > s; 
    for(ll i = 0 ; i  < n ; ++i){
        ll x ; 
        cin >> x; 
        s.insert(x); 
    }
    cout << s.size() << "\n"; 
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