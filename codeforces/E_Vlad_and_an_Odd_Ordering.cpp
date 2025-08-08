#include<bits/stdc++.h>
#define ll long long
#define all(x) x.begin(), x.end()
using namespace std;


void debug_vector(vector< ll >&a){
    for(auto x : a ) cout << x  << " "  ;
    cout << "\n"; 
    return; 
}

ll gcd(ll a, ll b )
{
    if(b==0) return a ;
    return gcd(b,a%b)  ;
}

void solve()
{
    ll n, k; 
    cin >> n  >> k;
    ll c = 2, d = 0, sum = 0;
    for(ll i = 0 ;; ++i){
        sum += (n+d)/c;
        if(k > sum){
            c += 2;
            d++;
        }
        else{
            ///first element is d.
            break; 
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
///accepted.