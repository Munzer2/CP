#include<bits/stdc++.h>
#define ll long long
#define all(x) x.begin(), x.end()
#define pb(x) push_back(x)
using namespace std;

ll MOD = 1e9 + 7; 

void debug_vector(vector<ll>& a) {
    for (auto x : a) cout << x << " ";
    cout << "\n";
    return;
}



ll bin_exp(ll a, ll b) {
    if(b == 0) return 1;
    ll res = bin_exp(a,b/2);
    if(b%2) return ((res*res)%MOD *a)%MOD; 
    return (res*res)%MOD; 
}

void solve() {
    ll a,b; 
    cin >> a >> b; 
    cout << bin_exp(a,b) << "\n"; 
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll tt;
    cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}