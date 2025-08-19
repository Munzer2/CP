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

/// check all subsets of an array to take the minimum score
void check(vector< ll > &arr, ll sum) {
    ll m = arr.size();
    m = (1 << m);
    ll best = LLONG_MAX;
    for(ll i = 0; i< m ; ++i) {
        ll s = 0; 
        for(ll j = 0; j < arr.size(); ++j) {
            if((i & (1<<j))) s += arr[j];
        }
        best = min(best, abs(sum - 2*s));
    }
    cout << best << "\n";
    return; 
}

void solve() {
    ll n ; 
    cin >> n; 
    vector< ll > a(n) ;
    ll s = 0 ;  
    for(auto &x  :a ) { cin >> x; s += x ; } 
    check(a,s);
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