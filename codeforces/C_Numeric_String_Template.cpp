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


ll calc_mex(vector< ll > a){
    ll mex = 0;
    sort(all(a));
    for(ll i = 0; i < a.size(); ++i){
        if(mex == a[i]) mex++;
    }
    return mex; 
}

void solve()
{
    ll n; 
    cin >> n ; 
    vector< ll > a(n); 
    for(auto &x : a ) cin >> x; 
    ll q; 
    cin >> q; 
    while(q--){
        string s ; 
        cin >> s ;
        if(s.size() != n) cout << "NO\n"; 
        else{
            ll f = 0;
            vector< ll > c(26,1e15);
            for(ll i = 0 ; i < n; ++i){
                if(c[s[i] - 'a'] == 1e15){
                    c[s[i]- 'a'] = a[i];
                }
                else{
                    if(c[s[i] - 'a'] == a[i]); 
                    else{
                        f = 1; 
                        break;
                    } 
                }
            }
            bool ok = true; 
            sort(all(c)); 
            for(ll i = 0 ; i < 25; ++i){
                if(c[i] == 1e15) break;
                ok &= (c[i] != c[i+1]);
            }
            if(f) cout << "NO\n"; 
            else cout << (ok ? "YES\n" : "NO\n");
        }
    }
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