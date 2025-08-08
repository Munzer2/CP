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
    cin >> n ; 
    vector< ll > a(n); 
    for(auto &x : a)  cin >> x;
    ll ans = 0 , mx = a[0]; 
    for(ll i = n-1; i >= 1; --i){
        if(a[i-1] > a[i]){
            ll check = a[i-1] - a[i];
            if(ans >= check){ 
                a[i-1] = a[i];
                ans++;
            }
            else a[i-1]-= ans;
        }
        else{
            ans += a[i] - a[i-1]+1; 
        }
    }
    ans += a[0]; 
    cout << ans << "\n" ;  
}

int main(){
    ll tt; 
    cin >> tt; 
    while(tt--){
        solve() ;
    }
    return 0 ;  
}
///accepted. If I want to solve using dp then dp[i] = max(dp[i+1]+1,h[i])
/// dp[i] means minimum time for i-th flower to get to height 0.