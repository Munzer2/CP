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


void solve()
{
    string s ; 
    cin >> s; 
    ll n = s.size() ; 
    vector< ll > pre(n,0); pre[0] = (s[0] == '1' ? 1 : 0); 
    for(ll i = 1; i< n; ++i) pre[i] = pre[i-1] + (s[i] == '1' ? 1: -1);
    ll ans = 0;
    map< ll, vector< ll > >mp;
    for(ll i =0 ; i < n; ++i){
        if(mp[pre[i]].size() == 0){
            mp[pre[i]].pb(i+1);
        }
        else{
            mp[pre[i]].pb((mp[pre[i]].back() + i+1)%Mod);
        }
    }
    map< ll, ll> cnt;
    for(ll i = 0; i < n; ++i){
        if(cnt[pre[i]] == 0){
        }
        else{
            ll c  = ( ans + mp[pre[i]][cnt[pre[i]]-1])%Mod;
            ans = (c*(n-i+1))%Mod;
        }
        cnt[pre[i]]++;
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
