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
    ll n  ;
    cin >> n ;
    vector< ll > a(n),diff ;
    for(auto &x : a ) cin >> x;
    ll mx = -1; 
    for(ll i = 1 ; i < n; ++i){
        if(a[i-1]> a[i]){
            mx = max(mx,a[i-1]); 
            diff.push_back(mx - a[i]);
        }
        else if(mx > a[i]){
            diff.push_back(mx - a[i]);
        }
    }
    if(diff.size() == 0){
        cout << "0\n"; 
        return; 
    }
    // debug_vector(diff);
    sort(all(diff));
    ll c = diff.size(); 
    ll curr = 0, ans = 0;
    for(ll i = 0 ; i < c ; ++i){
        ans += (diff[i] - curr)*(c-i+1);
        curr = diff[i];
    }
    cout << ans << "\n"; 
    return;
}
 
int main(){
    ll tt; 
    cin >> tt; 
    while(tt--){
        solve() ;
    }
    return 0 ;  
}
///accepted. But better imp can be done I guess.