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
    ll n , x ; 
    cin >> n >> x; 
    ll ans = 0;
    for(ll i = 1;  i <= n && i <= x; ++i){
        for(ll j = 1; i*j <= n && j <= x -i ; ++j){
            ans +=  min( x - i - j,(n- (i*j))/(i+j));
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
