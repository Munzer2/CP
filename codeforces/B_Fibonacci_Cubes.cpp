#include<bits/stdc++.h>
#define ll long long
#define all(x) x.begin(), x.end()
#define pb(x) push_back(x)
using namespace std;

void debug_vector(vector<ll>& a) {
    for (auto x : a) cout << x << "";
    cout << "\n";
    return;
}

void solve() {
    ll n , m ; 
    cin >> n >> m; 
    vector< ll > fib(n+1,0), ans(m,0); 
    fib[0] = 1, fib[1] = 2;
    for(ll i = 2 ;i < n+1 ; ++i) {
        fib[i] = fib[i-1] + fib[i-2];
    } 
    for(ll i = 0 ;i < m ; ++i ) {
        vector< ll > v(3); 
        for(auto &x : v) cin >> x; 
        sort(all(v));
        if(v[0] < fib[n-1] || v[2] < fib[n]) continue;
        ans[i] = 1;
    }
    debug_vector(ans); 
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


///accepted.