#include<bits/stdc++.h>
#define ll long long
#define all(x) x.begin(), x.end()
using namespace std;


void debug_vector(vector< ll >&a){
    for(auto x : a ) cout << x  << " "  ;
    cout << "\n"; 
    return; 
}

ll gcd(ll a, ll b )
{
    if(b==0) return a ;
    return gcd(b,a%b)  ;
}

vector< ll > inp; 

ll check(ll i1, ll i2){
    if(inp[i1] == inp[i2]){
        if(inp[i1+1] == inp[i2 + 1]){
            if(inp[i1+2] != inp[i2+2]) return 1; 
            else return 0;
        }
        else {
            if(inp[i1+2] == inp[i2+2]) return 1; 
            else return 0;
        }
    }
    else{
        if(inp[i1+1] != inp[i2+1] || inp[i1+2] != inp[i2+2] ) return 0; 
        else return 1;
    }
}

void solve()
{
    ll n ; 
    cin >> n ; 
    inp.resize(n);
    ll ans = 0;
    for(auto &x : inp ) cin >> x; 
    for(ll i = 0 ; i < n-2; ++i){
        for(ll j = i+1; j < n-2; ++j){
            if(check(i,j)) ans++;
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