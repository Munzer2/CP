#include<bits/stdc++.h>
#define ll long long
using namespace std;


void debug_vector(vector< ll >&a){
    for(auto x : a ) cout << x  << " "  ;
    cout << "\n"; 
    return; 
}

ll extract_highest_twos_power(ll n){
    unsigned int mask = 1; 
    for(ll i =0; i <31; ++i){
        if(mask & n){
            return mask; 
        }
        mask <<= 1; 
    }
    return 0;
}

void solve()
{
    ll x, y; 
    cin >> x >> y; 
    ll c = x^y;
    cout << extract_highest_twos_power(c) << "\n"; 
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