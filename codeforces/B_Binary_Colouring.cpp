#include<bits/stdc++.h>
#define ll long long
using namespace std;
///loving this extension fr.
///rainy day today. mon ta kemon kemon kore.


void debug_vector(vector< ll >&a){
    for(auto x : a ) cout << x  << " "  ;
    cout << "\n"; 
    return; 
}

void solve()
{
    ll x ; 
    cin >> x;
    unsigned int mask  =1 ;
    vector< ll > ans; 
    ll cnt = 0 ;
    for(ll i = 0; i < 31; ++i)
    {
        if( mask & x ) 
        {
            ans.push_back(1); 
        }
        else ans.push_back(0);
        mask <<= 1; 
    }
    for(ll i =0;  i < ans.size(); )
    {
        if( ans[i]) { cnt++; ++i ;} 
        else{
            if(cnt == 0) { ++i; continue; }
            if( cnt == 1) { ++i ; cnt =0 ; continue;}
            for(ll k = i-cnt; k <= i-1; ++k){
                if( k == i-cnt ) ans[k] =  -1; 
                else ans[k] = 0;
            }
            cnt = 0;
            ans[i] = 1;
        }
    }
    cout << ans.size() << "\n"; 
    debug_vector(ans); 
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