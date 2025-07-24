#include<bits/stdc++.h>
#define ll long long
#define all(x) x.begin(), x.end()
#define pb(x) push_back(x)
using namespace std;

void debug_vector(vector<ll>& a) {
    for (auto x : a) cout << x << " ";
    cout << "\n";
    return;
}

ll _dif(ll n, vector< ll > &digs) {
    ll cnt =0 ;  
    while(n) {
        cnt++;
        digs.pb(n%10); 
        n/= 10; 
    }
    return cnt; 
}

ll check(ll n , ll dig) {
    while(n) {
        if(n%10 == dig) return 1;
        n/=10; 
    }
    return 0; 
}

ll INF = 1e9; 
void solve() {
    ll n ; 
    cin >> n ; 
    if(n <= 9) {
        cout << "1\n"; 
        return; 
    }
    vector<ll> dp(n+1, INF);
    for(ll i = 1; i <= 9; ++i) dp[i] = 1;
    for(ll i = 10; i <= n ; ++i) {
        for(ll j = 1; j <= 9; ++j) {
            if( !check(i,j) ) continue;
            dp[i] = min(dp[i-j] + 1 , dp[i]); 
        }
    }
    cout << dp[n] << "\n";  
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll tt=1;
    while (tt--) {
        solve();
    }
    return 0;
}


///accepted. dp[i] ---> state means minimum moves to make 0 from i.