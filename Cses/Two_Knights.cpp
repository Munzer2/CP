#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long
#define all(x) x.begin(), x.end()
#define pb(x) push_back(x)
using namespace std;

void debug_vector(vector<ll>& a) {
    for (auto x : a) cout << x << " ";
    cout << "\n";
    return;
}

ll get(ll n ) {
    ll d = n*n - 1; 
    if(n <= 2) {
        return d*(d+1) / 2;
    }
    d = (d*(d+1))/2;
    ll c = 4*(n-2) + 2;
    if(n == 3) return (d - c - 2); 
    ll e = 6*(n-2) + 2; 
    return (d - c - e - (n-2)*(n-4)*4 - 2*(n-4));  
}

void solve() {
    ll n ; 
    cin >> n; 
    for(ll i = 1 ; i <= n; ++i) {
        cout << get(i) << "\n"; 
    }
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll tt = 1;
    // cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}


///accepted.