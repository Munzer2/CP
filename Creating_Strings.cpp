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
    string s; 
    cin >> s; 
    vector< string > ans;
    sort(all(s));
    ans.pb(s);
    while(next_permutation(all(s))){
        ans.pb(s);
    }
    cout << ans.size() << "\n"; 
    for(auto x : ans) cout << x << "\n";
    return; 
}

int main(){
    ll tt  = 1; 
    // cin >> tt; 
    while(tt--){
        solve() ;
    }
    return 0 ;  
}