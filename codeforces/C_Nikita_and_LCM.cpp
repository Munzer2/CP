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

ll dp[];

ll recur(vector< ll >&a, ll strt, ll end){
    if(strt >= end ) return 0;
    if( a[strt] == a[end]) return 2+recur(a,strt+1,end-1); 
    return max(recur(a,strt,end-1), recur(a,strt +1, end));
}

void solve()
{
    ll n ; 
    cin >> n ; 
    vector< ll > a(n);
    for(auto &x : a ) cin >> x;
    cout << recur(a,0,n-1) << "\n";    
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