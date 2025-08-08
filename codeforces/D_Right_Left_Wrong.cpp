#include<bits/stdc++.h>
#define ll long long
#define all(x) x.begin(), x.end()
#define pb(x)  push_back(x)
using namespace std;


void debug_vector(vector< ll >&a){
    for(auto x : a ) cout << x  << " ";
    cout << "\n"; 
    return; 
}


void solve()
{
    ll n; 
    cin >> n ;
    vector< ll > a(n); 
    string s; 
    for(auto &x : a) cin >> x; 
    cin >> s ;
    vector< ll > r(n); 
    r[0]  =(s[0] == 'R'?1 : 0);
    for(ll i = 1; i <  n; ++i){
        if(s[i] == 'R') r[i] = r[i-1] + 1;
        else r[i] = r[i-1];
    }
    ll l = 0;
    ll sum = 0 ;
    for(ll i = 0; i < n; ++i){
        if(s[i] == 'R'){
            if(l == 0) continue;
            if(i+1 < n){
                ll d = r[n-1] - r[i];
                if(d >= l){
                    sum += (a[i]*l);
                }
                else{
                    sum += (a[i]*l); 
                    l--;
                }
            }
            else{
                sum += a[i]*l; 
                l--;
            }
        }
        else{
            if(i+1< n){
                ll d = r[n-1]  - r[i];
                if(l + 1 <= d) { 
                    l++;
                    sum += a[i]*l;
                }
                else sum += a[i]*l;
            }
            else{
                ///nothing.
            }
        }
    }
    cout << sum << "\n";
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

//accepted.
