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
    ll mex = 1;
    vector< ll > a(n-1); 
    for(ll i = 0 ; i < n-1; ++i){
        cin >> a[i];
    }
    sort(all(a)); 
    for(ll i = 0 ; i < n-1; ++i){
        if(a[i] == mex) mex++;
    }
    cout << mex << "\n";
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