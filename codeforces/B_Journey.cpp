#include<bits/stdc++.h>
#define ll long long
#define all(x) x.begin(), x.end()
#define pb(x) push_back(x)
using namespace std;

void debug_vector(vector<ll>& a) {
    for (auto x : a) cout << x << " ";
    cout << "\n";
    return;
}

void solve() {
    ll n,a,b,c; 
    cin >> n >> a >> b >> c; 
    ll d = (a+b+c);
    ll check = n/d;
    ll ans = check;  
    n-= (check*d);
    ll ans1 = 0; 
    if(n <= a && n > 0) ans1 += 1;
    else if( n <= a+b && n > 0) ans1 += 2;
    else if( n <= a+b+c && n > 0 ) ans1 += 3;
    cout << ans1 + ans*3 << "\n"; 
    return;
}

int main() {
    ll tt;
    cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}