#include<bits/stdc++.h>
#define ll long long
#define all(x) x.begin(), x.end()
using namespace std;


void debug_vector(vector< ll >&a){
    for(auto x : a ) cout << x  << " "  ;
    cout << "\n"; 
    return; 
}

void solve()
{
    ll n , l , r; 
    cin >> n >> l >> r; 
    vector< ll > a(n) ; 
    for(auto &x : a ) cin >> x; 
    vector< ll > pre(n+1,0);  
    ll ans = 0 ; 
    for(ll i = 1;  i<= n ; ++i){
        pre[i] = pre[i-1] + a[i-1]; 
    }
    ll j, i = 0, flag = 0;
    // debug_vector(pre); 
    for(j = 1; j <= n; ++j){
        while(i < j && pre[j] - pre[i] > r) ++i;
        if(pre[j] - pre[i] <= r && pre[j] - pre[i] >= l ){
            ans++; 
            i = j ; 
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