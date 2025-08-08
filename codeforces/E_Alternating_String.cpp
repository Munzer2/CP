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

ll odd(string s) {
    ll n = s.size(); 
    vector< ll > c(26,0);
    for(ll i = 0 ; i < n; i+=2){
        c[s[i]-'a']++; 
    }
    ll mx = -1, mx_ind = -1;
    for(ll i = 0 ; i< 26; ++i) {
        if( mx < c[i]) {
            mx = c[i];
            mx_ind = i;
        }
    }
    ll cnt = 0;
    for(ll i = 0; i < 26; ++i) {
        cnt += (i != mx_ind ? c[i] : 0) ; 
    }
    return cnt; 
}

ll even(string s) {
    ll n = s.size(); 
    vector< ll > c(26,0);
    for(ll i = 1 ; i < n; i+=2){
        c[s[i]-'a']++; 
    }
    ll mx = -1, mx_ind = -1;
    for(ll i = 0 ; i< 26; ++i) {
        if( mx < c[i]) {
            mx = c[i];
            mx_ind = i;
        }
    }
    ll cnt = 0;
    for(ll i = 0; i < 26; ++i) {
        cnt += (i != mx_ind ? c[i] : 0) ; 
    }
    return cnt; 
}


void solve()
{
    ll n ; 
    cin >> n; 
    string s; 
    cin >> s; 
    if(n%2) { 
        ll mx_ev = -1, mx_odd = -1;
    }
    else{
        ll ans = even(s) + odd(s) ; 
        cout << ans << "\n"; 
    }
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
