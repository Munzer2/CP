#include<bits/stdc++.h>
#define ll long long
#define all(x) x.begin(), x.end()
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
    ll n; 
    cin >> n; 
    vector< vector< ll > > a(n,vector< ll > (3));
    for(ll i = 0 ; i < n; ++i){
        for(ll j = 0 ; j < 3; ++j ) cin >> a[i][j];
    }
    vector< vector< ll >> dp(n,vector< ll> (3,0));
    for(ll j = 0 ; j < 3; ++j ) dp[0][j] = a[0][j]; 
    for(ll i = 1; i < n; ++i){
        for(ll j = 0 ; j< 3; ++j){
            dp[i][j] = max(dp[i-1][(j+1)%3], dp[i-1][(j+2)%3]) + a[i][j];
        }
    }
    ll mx = -1;
    for(ll i = 0 ; i < 3; ++i ) mx = max(mx,dp[n-1][i]); 
    cout << mx << "\n";  
    return;
}

int main(){
    ll tt = 1; 
    // cin >> tt; 
    while(tt--){
        solve() ;
    }
    return 0 ;  
}
///accepted.