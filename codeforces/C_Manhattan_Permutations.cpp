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
    ll n ,p; 
    cin >> n >> p;
    ll mx= 0; 
    for(ll i = 1; i <= n; ++i) mx += abs(n-i+1-i); 
    if(p > mx || p%2) { cout << "No\n"; return; } 
    cout << "Yes\n";
    vector< ll > ans(n);
    for(ll i = 0 ; i < n ; ++i ) ans[i] = i+1;
    ll low = 1;
    for(ll k = n; ; --k){
        ll check = k-(p/2);
        if(check < low){
            ans[low-1] = k; 
            ans[k-1] = low;
            p-= 2*(k-low); 
            low++;
        }
        else{
            ans[check-1] = k ;
            ans[k-1] = check;  
            break;
        }
    }
    debug_vector(ans);
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