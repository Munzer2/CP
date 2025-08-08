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
    ll n, w; 
    cin >> n >> w; 
    vector< vector< ll > > dp(n+1,vector< ll > (w+1,0));
    vector< pair< ll,ll >> vect(n);
    for(ll i = 0 ; i< n; ++i){
        cin >> vect[i].first  >> vect[i].second;
    }
    for(ll i = 1; i <= n; ++i){
        for(ll j = 1; j <= w; ++j){
            if(vect[i-1].first <= j ) dp[i][j] = max(dp[i-1][j],vect[i-1].second + dp[i-1][j-vect[i-1].first]);
            else dp[i][j] = dp[i-1][j];
         }
    }
    cout << dp[n][w] << "\n"; 
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