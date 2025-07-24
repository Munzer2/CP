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
    ll n ; 
    cin >> n ; 
    if(n <= 3) {
        if(n == 1) { cout << "1\n"; } 
        else cout << "NO SOLUTION\n"; 
        return; 
    }
    ll cnt = n; 
    vector< ll > ans;
    for(ll i = 2; i <= n; i+=2) ans.pb(i);
    for(ll i = 1; i <= n; i+=2) ans.pb(i);
    debug_vector(ans); 
    return;
}


int main() {
    ll tt = 1;
    // cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}