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
    ll b,c,d ; 
    cin >> b >> c >> d; 
    uint64_t mask = 1, a = 0 ;
    ll f = 1; 
    for(ll i = 0; i < 61; ++i) { 
        if((mask & b) == 0 && (mask&c)) {
            if((mask & d)) {
                f = 0; 
                break;
            }
        }
        else if((mask & c) && (mask & b)) {
            if((mask & d) == 0) a |= mask;  
        }
        else if((mask & b) && (mask&c) == 0) {
            if((mask & d) == 0) {
                f = 0; break; 
            }
        }
        else {
            if((mask & d)) a |= mask; 
        }
        mask <<= 1; 
    }

    if(f) cout << a << "\n"; 
    else cout << "-1\n"; 

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
///accepted. 