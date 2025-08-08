#include<bits/stdc++.h>
#define ll long long
using namespace std;


void debug_vector(vector< ll >&a){
    for(auto x : a ) cout << x  << " "  ;
    cout << "\n"; 
    return; 
}

ll check_z(string s){
    for(auto x : s ) {
        if( x =='0' ) return 1;
    }
    return 0; 
}

void solve()
{
    ll n ; 
    cin >> n; 
    string s; cin >> s; 
    if(n <= 2) {
        cout << stoi(s) << "\n"; 
        return; 
    }
    if(n == 3 && s[1] == '0'){
        ll a = stoi(s.substr(0,2));
        ll b = stoi(s.substr(1,2));
        ll a1= min(a*(s[2]-'0'), a+(s[2]-'0'));
        ll a2= min(b*(s[0]-'0'),b+(s[0]-'0'));
        cout << min(a1,a2) << "\n"; 
        return; 
    }
    ll ans = 1e14; 
    if(check_z(s)) { cout << "0\n"; return;  }
    for(ll i = 0; i < n-1; ++i){
        string c = s.substr(i,2);
        // cout << c << "\n";
        ll d = stoi(c), check1 = 0, check2 =0;
        for(ll j = 0 ; j < i; ++j){
            check1 += (s[j] != '1' ? s[j]-'0' : 0); 
        } 
        if(i != 0 && check1 == 0) check1 = 1; 
        for(ll j = i+2; j < n; ++j){
            check2 += (s[j] != '1' ? s[j]- '0' : 0);
        }
        if(i+2 != n-1 && check2 == 0) check2 = 1;
        if(check1 == 1 && check2 == 1){ 
            ans = min(ans,d); 
        } 
        else{
            if(check1 == 1) ans = min(ans, check2 + d); 
            else if(check2 == 1) ans = min(ans,check1+d); 
            else ans = min(ans, check1 + check2 + d ) ; 
        }
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