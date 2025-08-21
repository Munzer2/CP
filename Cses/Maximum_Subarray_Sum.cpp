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
    vector< ll > a(n); 
    for(auto &x : a ) cin >> x ; 
    ll s = 0;
    ll best = LLONG_MIN;
    for(ll i = 0 ;i < n ; ++i) {
        s+= a[i]; 
        best = max(best,s);
        if(s < 0) {
            s= 0;
        }
    }
    cout << best << "\n";
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


///passed.