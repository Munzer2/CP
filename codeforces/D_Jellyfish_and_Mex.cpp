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


ll calc_mex(vector< ll > a){
    ll mex = 0;
    sort(all(a));
    for(ll i = 0; i < a.size(); ++i){
        if(mex == a[i]) mex++;
    }
    return mex; 
}

void solve()
{
    ll n ; 
    cin >> n; 
    vector< ll > a(n); 
    for(auto &x : a)  cin >> x;
    ll mex = calc_mex(a);
    if(!mex){
        cout << "0\n"; 
        return;
    }
    vector< ll > pre(mex, 0); 
    for(ll i = 0 ; i < n; ++i){
        if(a[i] < mex) pre[a[i]]++;
    }
    vector< ll > dp(mex,0);
    dp[0] = (pre[0]-1)*mex;
    for(ll i = 1; i < mex; ++i){
        for(ll j = 0;  j<= i; ++j){
            dp[i] = 
        }
    }
    // debug_vector(dp);
    cout << dp.back() << "\n";
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