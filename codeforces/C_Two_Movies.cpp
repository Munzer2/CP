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
    ll n ; 
    cin >> n ; 
    vector< ll > a(n), b(n) ; 
    for(auto &x : a ) cin >> x; 
    for(auto &x : b ) cin >> x;
    ll pos = 0, neg =0, s1 =0, s2 =0; 
    for(ll i = 0 ; i < n; ++i ) {
        if(a[i] == b[i]){
            if(a[i] == 1) pos++; 
            else if(a[i] == -1) neg++;
        }
        else{
            if(a[i] >= b[i]) s1 += a[i];
            else s2 += b[i];
        }
    }
    while(pos--){
        if(s1 <= s2) s1++; 
        else s2++;
    }
    while(neg--){
        if(s1 <= s2) s2--; 
        else s1--;
    }
    cout << min(s1,s2) << "\n";
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
///a nice problem. Greedy. I am dividing the pos and neg equally among the two movies.