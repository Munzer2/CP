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
    ll n,t ; 
    cin >> n >> t;
    vector< ll > a(n) ;
    map< ll, vector< ll >> ind;  
    for(ll i = 0; i < n; ++i) {
        cin >> a[i]; 
        ind[a[i]].pb(i+1);
    }
    for(ll i = 0 ; i < n; ++i){
        ll d = t - a[i];
        if(d == a[i]){
            if(ind[a[i]].size() >= 2) {
                ll c;
                for(auto x : ind[a[i]]){
                    if(x != i+1) {c = x; break;}
                }
                cout << i+1 << " " << c << "\n"; 
                return; 
            }
        }
        else{
            if(ind[d].size() >= 1){
                cout << i+1 << " " << ind[d][0] << "\n"; 
                return; 
            }
        }
    }
    cout << "IMPOSSIBLE\n"; 
    return; 
}

int main(){
    ll tt = 1; 
    // cin >> tt; 
    while(tt--){
        solve() ;
    }
    return 0 ;  
}