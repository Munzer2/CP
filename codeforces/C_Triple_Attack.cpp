#include<bits/stdc++.h>
#define ll long long
// #define all(x) x.begin(), x.end()
#define pb(x)  push_back(x)
using namespace std;


void debug_vector(vector< ll >&a){
    for(auto x : a ) cout << x  << " "  ;
    cout << "\n"; 
    return; 
}

ll gcd(ll a, ll b){
    if(b == 0) return a;
    return gcd(b,a%b);
}



void solve()
{
    ll n ; 
    cin >> n ; 
    vector< ll > a(n) ;
    for(auto &x : a) cin >> x; 
    ll t = 0;
    for(ll i = 0 ; i < n; ++i){
        ll moves = 0; 
        for(ll j = t+1; ; ++j){
            if(a[i] <= 0) break;
            a[i] -= (j%3 == 0 ? 3 : 1) ; 
            moves++; 
            if(j%3 == 0) break;
        }  
        if(a[i] > 0){
            moves += (a[i]/5)*3; 
            a[i] -= (a[i]/5)*5;
            moves += (a[i]  >= 3 ? 3 : a[i]); 
        } 
        t += moves;
    }    
    cout << t << "\n"; 
    return; 
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    ll tt =1; 
    // cin >> tt; 
    while(tt--){
        solve() ;
    }
    return 0 ;  
}

///nice problem. accepted. 