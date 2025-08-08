#include<bits/stdc++.h>
#define ll long long
using namespace std;


void debug_vector(vector< ll >&a){
    for(auto x : a ) cout << x  << " "  ;
    cout << "\n"; 
    return; 
}

ll gcd(ll a, ll b )
{
    if(b==0) return a ;
    return gcd(b,a%b)  ;
}


void solve()
{
    ll n ; 
    cin >> n ;
    vector< ll > a(n);  
    for(auto &x : a ) cin >> x;
    ll c = 0; 
    vector< ll> pre(n,0);
    pre[0] = a[0]; 
    for(ll i = 1; i < n ; ++i){
        pre[i] = pre[i-1] + a[i];
    } 
    // debug_vector(pre); 
    ll ans = -1e15;
    for(ll i = 0 ; i< n; ++i){
        ans = max( ans, pre[n-1] - pre[i] + abs(pre[i])); 
    }
    cout << ans << "\n"; 

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