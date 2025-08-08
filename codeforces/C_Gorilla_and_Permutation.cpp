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
    ll n ,m,k; 
    cin >> n >> m >> k;
    map<ll, ll > mp;
    for(ll i = n ; i >= k  ; --i) {  mp[i] = 1; cout << i << " ";  }
    for(ll i = m+1; i < k ; ++i ) { mp[i] = 1; cout << i << " ";  }
    for(ll i = 1; i <= n ; ++i) {
        if(!mp[i]) cout << i << " "; 
    } 
    cout << endl ; 
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