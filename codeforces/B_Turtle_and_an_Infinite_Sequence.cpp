#include<bits/stdc++.h>
#define ll long long
using namespace std;


void debug_vector(vector< ll >&a){
    for(auto x : a ) cout << x  << " "  ;
    cout << "\n"; 
    return; 
}

ll check_twos_power(ll n){
    for(ll i = 0; i < 31; ++i){
        if( n == (1<<i) ) return 1;
    }
    return 0;
}




void solve()
{
    ll n,m ; 
    cin >> n >> m;
    ll lower = (n-m < 0 ? 0 : n-m);
    uint64_t curr_pow, ans = 0;
    for(ll  i = lower; i <= n+m ;){
        if(check_twos_power(i)){
            if(i <= n+m ) 
            {
                ans |= i;
                i *=2; 
            }
            else 
            {
                curr_pow = (i>>1); 
                break ;
            }
        } 
        else {
            ans |= i; 
            ++i; 
        }
    } 
    for(ll c = curr_pow+1; c <= n+m ; ++c ) ans |= c ; 
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