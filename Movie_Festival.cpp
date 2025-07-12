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
    ll n; 
    cin >> n; 
    vector< vector< ll >> _pairs(n, vector< ll >(2));
    for(ll i = 0; i < n ; ++i) {
        cin >> _pairs[i][0] >> _pairs[i][1]; 
    }
    sort(all(_pairs), [](const vector<ll>& a, const vector<ll>& b) {
        return a[1] < b[1];
    });

    // for(ll i = 0 ;i < n ; ++i) {
    //     debug_vector(_pairs[i]); 
    // }    
    ll ans = 0, last_end = -1;
    for(ll i = 0 ; i < n ; ++i) {
        if(_pairs[i][0] >= last_end) {
            ans++;
            last_end = _pairs[i][1]; 
        }
    }
    cout << ans << "\n"; 
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