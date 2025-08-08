#include<bits/stdc++.h>
#define ll long long
#define all(x) x.begin(), x.end()
using namespace std;


void debug_vector(vector< ll >&a){
    for(auto x : a ) cout << x  << " "  ;
    cout << "\n"; 
    return; 
}

ll check(string s, string s1,ll ind){
    ll cnt = 0; 
    for(ll i = 0; i < s.size(); ++i){
        if(s[i] == s1[ind]){
            ind++;
            cnt++;
        }
    }
    return cnt;
}

void solve()
{
    // ll n ; 
    // cin >> n ; 
    string a, b; 
    cin >> a >> b;
    ll ans = 1e15;
    for(ll i = 0 ; i < b.size(); ++i){
        // cout << check(a,b,i) << "\n"; 
        ans = min(ans,b.size() - check(a,b,i) + a.size()); 
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