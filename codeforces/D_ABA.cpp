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


void solve()
{
    string s; 
    cin >> s; 
    map< ll, vector< ll > > mp; 
    for(ll i = 0 ; i < s.size(); ++i)  mp[s[i]-'A'].push_back(i);
    vector< ll > pre[26]; 
    for(ll i = 0; i < 26; ++i) {
        if(mp[i].size()) {
            pre[i].resize(mp[i].size(),0);
            for(ll j = 0; j < mp[i].size(); ++j ) {
                if(!j) pre[i][j] = mp[i][j]; 
                else pre[i][j] = pre[i][j-1] + mp[i][j]; 
            }
            // debug_vector(pre[i]);
        }
    } 
    ll ans = 0;
    for(ll i = 0 ; i < 26; ++i) {
        if(mp[i].size()) {
            ll n = mp[i].size(); 
            for(ll j = 0; j < n; ++j) {
                ans -= (n-j-1);
                ans += pre[i][n-1] - pre[i][j]; 
                ans -= (n-j-1)*mp[i][j]; 
            }
        }
    }
    cout << ans << "\n"; 
    return; 
}


int main(){
    ll tt=1;  
    // cin >> tt; 
    while(tt--){
        solve() ;
    }
    return 0 ;  
}

///accepted