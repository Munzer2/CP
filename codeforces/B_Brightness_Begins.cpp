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



ll check(ll n) {
    ll d = sqrt(n) ; 
    return (d*d == n); 
}


void solve()
{
    ll k;
    cin >> k; 
    ll ans ; 
    ans = (ll)(sqrt(k) + 0.5) + k ; 
    cout << ans << "\n"; 

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