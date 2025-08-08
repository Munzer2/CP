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
    ll n , k ; 
    cin >> n >> k ; 
    vector< ll > a(n); 
    for(auto &x : a) cin >> x;
    if(n == 1){
        cout << a[0] << "\n"; 
        return; 
    } 
    sort(all(a));
    ll ans = 0;
    for(ll i = n-1; i >= 0 ; i-=2){
        if(i == 0) continue;
        ll c = min(a[i] - a[i-1],k);
        k-= c;
        a[i-1] += c; 
    }
    for(ll i = n-1; i > 0; i-=2){
        ans+=(a[i]- a[i-1]);
    }
    if(n%2) ans += a[0];
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
///horrible implementation.Accpeted.