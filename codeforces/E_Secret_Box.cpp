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


void solve()
{
    ll  x,y,z,k;
    cin >> x >> y >> z >> k; 
    ll  ans = 0;
    for(ll i= 1; i <= x ; ++i ){
        for(ll j = 1; j<= y; ++j){
            if( k %(i*j)) continue;
            ll c = k/(i*j);
            if(c > z ) continue; 
            ll poss = (ll)(x-i +1)*(y-j +1)*(z - c + 1); 
            ans = max(ans,poss); 
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