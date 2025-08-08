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
    ll n, k ; 
    cin >> n  >> k ; 
    vector< ll > a(n);
    map< ll, vector< ll >> mp;  
    for(auto &x : a ){
        cin >> x; 
        mp[x%k].push_back(x); 
    }
    ll check = 0, cnt = 0 ; 
    if(n%2) check++; 
    for(auto x : mp){
        if(x.second.size()%2) cnt++;
    }
    if(cnt == check){
        ll ans = 0;
        for(auto x : mp){
            ll sz =x.second.size();
            sort(all(x.second)); 
            // debug_vector(x.second);
            if(sz%2 == 0){
                for(ll i = 0 ; i < sz; i+=2) ans +=  (x.second[i+1]-x.second[i])/k; 
            }
            else{
                vector< ll > dp(sz,0);
                // cout << "DP : " << "\n"; 
                dp[0] = 0;
                for(ll i = 1; i < sz; i+=2) dp[i] = (i == 1 ? x.second[i] - x.second[i-1] : x.second[i] - x.second[i-1] + dp[i-2]);
                for(ll i = 2; i < sz; i+=2){
                    ////here dp[i] where i is odd means minimum ans up until i-th elements.
                    //// dp[i-1] means without i-th element.
                    ll c = dp[i-2] + x.second[i] - x.second[i-1]; ///taking both elements 
                    ll d = (i-3 < 0 ? 0 : dp[i-3]) + x.second[i] - x.second[i-2]; ///without the i-1 th element.
                    dp[i] = min(dp[i-1],min(c,d));
                }
                // debug_vector(dp); 
                ans += dp[sz-1]/k;
            }
        }
        cout << ans << "\n"; 
    }
    else cout << "-1\n"; 
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
///accepted. My first 1700 rated problem. A good one indeed.
/// Also solved it during shutdown of internet. What hideous times.