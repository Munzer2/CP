#include<bits/stdc++.h>
#define ll long long
using namespace std;


void debug_vector(vector< ll >&a){
    for(auto x : a ) cout << x  << " "  ;
    cout << "\n"; 
    return; 
}

void solve()
{
    ll n; 
    cin >> n ; 
    vector< ll > a(n), b(n+1);
    for(auto &x : a ) cin >> x; 
    for(auto &x : b ) cin >> x;
    ll ans = 0; 
    ll check = 0;
    for(ll i = 0; i < n; ++i){
        ans += abs(a[i]-b[i]);
        if(b[n]<= max(b[i],a[i]) && b[n] >= min(b[i],a[i])) check = 1;
    }  
    if(check) cout << ans+1 << "\n";///copying the element. 
    else{
        ll d = 1e15;
        for(ll i =0 ; i < n; ++i){
            d = min(d, min(abs(a[i]-b[n]), abs(b[i]-b[n])));
        }
        cout << d+ ans + 1<< "\n"; 
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