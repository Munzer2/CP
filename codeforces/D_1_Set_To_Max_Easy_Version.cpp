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
    vector< ll > a(n), b(n); 
    for(auto &x : a ) cin >> x; 
    for(auto &x : b ) cin >> x;
    if(a == b){
        cout << "YES\n"; 
        return;
    }
    
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