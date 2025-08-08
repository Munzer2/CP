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
    ll n; 
    cin >> n ;
    vector< pair< ll, ll > > a(n) ;
    vector< pair< ll, ll > > _s, _n;  
    for(ll i = 0  ; i < n; ++i) {
        cin >> a[i].first >> a[i].second; 
        if(a[i].first > a[i].second) {
            _n.push_back(a[i]);
        }
        else _s.push_back(a[i]); 
    } 
    sort(all(_s)); sort(all(_n));
    for(ll i = 0 ; i  <  _n.size(); ++i) cout << _n[i].first << " " << _n[i].second << "\n";  
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