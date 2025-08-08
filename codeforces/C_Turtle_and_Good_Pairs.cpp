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
    ll n ;
    cin >> n;
    string s ;
    cin >> s; 
    map< ll, ll > mp;
    for(auto c : s ) mp[c-'a']++;
    char curr = s[0];
    string ans = "";
    ans += curr;
    mp[curr-'a']--;
    for(ll i = 1 ; i < n; ++i){
        for(ll i = 0 ; i < 26; ++i){
            if(i != curr - 'a' && mp[i] > 0){
                curr = char(i+'a');
                break;
            } 
        }
        mp[curr- 'a']--;
        ans += curr; 
    } 
    cout << ans << "\n" ; 
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


///accepted.