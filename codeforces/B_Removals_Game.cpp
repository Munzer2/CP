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
    ll n ;
    cin >> n ; 
    vector< ll >A(n), B(n); 
    for(auto &x : A ) cin >> x ;
    for(auto &x : B) cin >> x  ; 
    vector< ll > C = A; 
    reverse(all(A));
    if(C == B || A == B) cout << "Bob\n"; 
    else cout << "Alice\n";
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