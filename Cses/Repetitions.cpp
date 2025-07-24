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
    string s ; 
    cin >> s; 
    vector< ll > a(26,0);
    a[s[0]- 'A']++;
    ll ans = -1; 
    for(ll i = 1; i < s.size(); ++i){
        if(s[i] == s[i-1]) a[s[i]-'A']++;
        else{
            ans = max(a[s[i-1]-'A'],ans);
            a[s[i-1]-'A'] = 0;
            a[s[i]-'A']++;
        }
    }
    ans = max(ans,a[s.back()-'A']);
    cout << ans << "\n";
    return; 
}

int main(){
    ll tt  = 1; 
    // cin >> tt; 
    while(tt--){
        solve() ;
    }
    return 0 ;  
}