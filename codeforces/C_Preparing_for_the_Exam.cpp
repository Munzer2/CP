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
    ll n,m,k ; 
    cin >> n >> m >> k;
    vector< ll > a(m);
    for(ll i = 0 ; i < m; ++i) cin >> a[i];
    map< ll, ll > mp; 
    for(ll i = 0;  i < k; ++i) {
        ll x ; 
        cin >> x;
        mp[x] = 1;
    } 
    if(k == n) {
        for(ll i = 0; i < m; ++i ) cout << "1"; 
        cout << "\n"; 
        return; 
    }
    if(k < n-1) {
        for(ll i =0 ;i < m; ++i) {
            cout << "0"; 
        }
        cout << "\n"; 
        return; 
    }
    // cout << mask << "\n";
    //here k == n-1
    ll ind = -1;  
    for(ll i = 1 ; i <= n; ++i) {
        if(mp[i] == 0) {
            ind = i ; 
            break; 
        }
    }
    for(ll i = 0 ; i < m; ++i) {
        if(ind == a[i]) cout << "1" ; 
        else cout << "0"; 
    }
    cout << "\n"; 
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