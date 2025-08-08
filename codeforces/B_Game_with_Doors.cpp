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
    ll a,b; 
    ll c,d; 
    cin >> a >> b; 
    cin >> c >> d;
    if(a > d || b < c){
        cout << "1\n";
        return; 
    }
    ll ans = 0; 
    ll mx = max(a,c);
    ll mn = min(b,d);
    ans = mn - mx; 
    if(b > mn || d > mn) ans++;
    if(a < mx || c < mx) ans++; 
    cout << ans << "\n";
    // debug_vector(vect);
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