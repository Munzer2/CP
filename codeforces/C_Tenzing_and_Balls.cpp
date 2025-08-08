#include<bits/stdc++.h>
#define ll long long
#define all(x) x.begin(), x.end()
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
    vector< ll > a(n) ;
    map< ll,ll > mp; 
    for(ll i = 0 ; i < n; ++i ) {
        cin >> a[i];
        mp[a[i]] = -1;
    }
    vector< ll > dp(n,0);
    for(ll i =0 ; i < n; ++i){
        if(i){
            if(mp[a[i]] == -1) dp[i] = dp[i-1];
            else{
                ll ind = mp[a[i]]; 
                if(ind == -1) dp[i] = dp[i-1];
                else if(ind == 0) dp[i] = max(dp[i-1], i- ind+1); 
                else dp[i] = max(dp[i-1],i-ind+1 + dp[ind-1]);
            }
        }
        mp[a[i]] = i;
    }
    debug_vector(dp);
    cout << dp[n-1] << "\n"; 
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