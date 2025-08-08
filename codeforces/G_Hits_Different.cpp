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

ll Max = 1e6 + 1;
vector< ll > dp(Max,0);

ll check(ll c){
    c-= 1;
    c*= 2;
    ll d = 1 + 4*c;
    ll e = sqrt(d);
    return (1+e)/2; 
}

void gen(){
    dp[1] = 1; 
    dp[2] = 5;
    dp[3] = 10;
    for(ll i = 4; i <= Max; ++i){
        ll row = check(i);
        ll fir = 1 + (row*(row-1))/2;
        ll lst = fir + row-1;
        if(i == fir || i == lst) {
            dp[i] = (i == fir ? dp[i-row+1] : dp[i-row]) + i*i;
        }
        else { 
            dp[i] = i*i + dp[i-row+1] + dp[i-row] - dp[i-2*row + 2];
        }  
    }
}

void solve()
{
    ll n ; 
    cin >> n ;
    cout << dp[n] << "\n";
    return;
}

int main(){
    gen();
    ll tt ; 
    cin >> tt; 
    while(tt--){
        solve() ;
    }
    return 0 ;  
}


///accepted. Good problem. 1600 rated.