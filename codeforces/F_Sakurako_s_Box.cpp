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

ll bin(ll x, ll y) {
    ll res = 1; 
    x %= Mod;
    while(y > 0) {
        if(y%2) {
            res = (res * x)%Mod; 
        }
        y /= 2; 
        x = (x*x)%Mod; 
    }
    return res;     
}

ll inv(ll p) {
    return bin(p,Mod-2); 
}

void solve()
{
    ll n ; 
    cin >> n ;
    vector< ll > a(n); 
    for(ll i = 0 ; i < n; ++i) {
        cin >> a[i] ; 
    }
    vector< ll > pre(n,0) ; 
    for(ll i = 0 ; i < n; ++i) {
        pre[i] = ((!i ? 0 : pre[i-1] ) + a[i])%Mod; 
    }
    ll a1=0; 
    ll a2 = (n*(n-1))/2;
    for(ll i = n-1; i>= 1 ; --i) {
        a1 = (a1 + (pre[i-1] * a[i])%Mod)%Mod;  
    }
    // debug_vector(pre); 
    // cout << a1 << "\n"; 
    ll ans = inv(a2)%Mod;
    ans = (ans*a1)%Mod;
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


///accepted.