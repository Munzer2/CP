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
    vector< ll > cnt(26,0); 
    for(auto x: s ) {
        cnt[x-'A']++; 
    }
    vector< char > ans; 
    ll cnt1 = 0;
    ll c= 0; 
    char d;  
    for(ll i = 0 ; i < 26; ++i){
        if(cnt[i]%2) { cnt1++; c = cnt[i]; d = char('A' + i);}
        else{
            ll d = cnt[i]/2;
            while(d>0) { ans.pb('A' + i); d--;}
        }
    }
    if(cnt1 > 1) cout << "NO SOLUTION\n"; 
    else{
        for(ll i = 0 ; i < ans.size(); ++i) cout << ans[i]; 
        for(ll i = 0 ; i < c; ++i) cout << d ;
        reverse(all(ans));
        for(ll i = 0 ; i < ans.size(); ++i) cout << ans[i] ; 
        cout << endl; 
    }
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