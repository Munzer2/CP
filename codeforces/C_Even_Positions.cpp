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
    ll n ; 
    cin >> n; 
    string s ; 
    cin >> s; 
    vector< ll > st(10,0);
    ll top = -1;
    ll ans = 0; 
    for(ll i = 0 ; i < n; i+=2){
        if(s[i+1] == ')'){
            if(top == -1) ans++;
            else{
                ans += (i-st[top]);
                top--;
                ans += (i+1-st[top]);
                top--; 
            }
        }
        else{
            if(top == -1){
                st[++top] = i;
                st[++top] = i+1;
            }
            else{
                ans += i-st[top];
                st[top] = i+1;
            }
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
///accepted.
