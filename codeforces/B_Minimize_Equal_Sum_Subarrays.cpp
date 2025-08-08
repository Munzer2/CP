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
    vector< ll > a(n) ; 
    for(auto &x: a ) cin >> x; 
    cout << a.back() << " " ; 
    for(ll i = 0 ; i < n-1; ++i) cout << a[i] << " "; 
    cout << endl;
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