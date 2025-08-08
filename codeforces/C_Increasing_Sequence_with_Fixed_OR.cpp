#include<bits/stdc++.h>
#define ll long long
#define all(x) x.begin(), x.end()
using namespace std;


void debug_vector(vector< ll >&a){
    for(auto x : a ) cout << x  << " "  ;
    cout << "\n"; 
    return; 
}

ll check(ll n){
    uint64_t mask = 1; 
    ll c = 0; 
    for(ll i =0 ;  i< 61; ++i){
        if(mask & n) c = mask; 
        mask <<= 1;
    }
    return c; 
}

void check2(ll n, ll c, vector< ll > &ans){
    ll mask = c; 
    for(ll i = 0 ; ; ++i){
        if(mask == 0) break;
        if(mask&n){
            if((mask^n) != 0) ans.push_back(mask^n);
        } 
        mask >>= 1; 
    }
    return;
}

void solve()
{
    ll n  ;
    cin >> n ; 
    vector< ll > ans; 
    check2(n,check(n),ans); 
    cout << ans.size() + 1 << "\n";
    if(ans.size() != 0) for(auto c : ans ) cout << c << " ";
    cout << n << "\n"; 
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


///accepted. Always keep an eye on the bounds.