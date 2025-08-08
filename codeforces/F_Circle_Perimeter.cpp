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


ll check(ll n ){
    ll d = ceil(sqrt(n*n/2));
    ll e = floor(sqrt((n+1)*(n+1)/2));
    return e-d+1;
}


void solve()
{
    ll n ; 
    cin >> n ; 
    if(n <=2) {
        cout << n*8 << "\n"; 
        return;
    }
    ll d = ceil((n*n)/2);
    cout << d << "\n";
    d = ceil(sqrt(d));
    ll ans = 0;
    for(ll i = n; i>= d; --i){
        ll c = ceil(sqrt(n*n - i*i));
        ll upper = floor(sqrt((n+1)*(n+1) - i*i));
        if(upper*upper + i*i == (n+1)*(n+1)) upper--;
        ans += (upper-c+1);
        cout << "I: " << i << ":     ";
        cout << c << " " << upper << "\n"; 
    }
    
    cout << 8*ans - 4 << "\n";
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
