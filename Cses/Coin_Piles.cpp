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
    cin >> a >> b; 
    ll mx = max(a,b), mn = min(a,b);
    if(mx > 2*mn) {
        cout << "NO\n";
        return; 
    }
    if((a+b)%3) cout << "NO\n"; 
    else cout << "YES\n"; 
    return; 
}

int main(){
    ll tt; 
    cin >> tt; 
    while(tt--){
        solve() ;
    }
    return 0 ;  
}