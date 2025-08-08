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

ll Mod = 1e9 + 7;

void solve()
{
    ll n ; 
    cin >> n ; 
    vector< ll > a(n); 
    ll mx = -1;
    for(auto &c : a ) cin >> c; 
    for(ll i = 0 ; i< n ; i+=2) mx = max(mx,a[i]); 
    cout << mx << "\n";
    return;
}

int main(){
    ll tt ; 
    cin >> tt; 
    while(tt--){
        solve() ;
    }
    return 0 ;  
}
///accepted.