#include<bits/stdc++.h>
#define ll long long
using namespace std;


void debug_vector(vector< ll >&a){
    for(auto x : a ) cout << x  << " "  ;
    cout << "\n"; 
    return; 
}

void solve()
{
    ll n; 
    cin >> n; 
    vector< ll > a(n); 
    for(auto &x: a ) cin >> x;
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