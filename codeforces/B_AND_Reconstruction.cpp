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
    cin >> n ; 
    vector< ll > a(n-1); 
    for(auto &c : a ) cin >> c; 
    vector< ll > ans(n);
    ans[0] = a[0];
    ll f =1; 
    for(ll i = 1 ; i < n-1; ++i){
        ans[i] = a[i-1] | a[i];
        if((ans[i] & ans[i-1]) != a[i-1]) {
            f = 0; 
            break; 
        }
    }
    if(!f) cout << "-1\n"; 
    else{
        ans[n-1] = a.back();
        if((ans[n-1] &  ans[n-2]) != a.back()) cout << "-1\n"; 
        else debug_vector(ans); 
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
///accepted.