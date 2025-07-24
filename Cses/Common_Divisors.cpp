#include<iostream>
#include<vector>
#include<algorithm>
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
    cin >> n ; 
    vector<ll> a(n);
    vector< ll > cnt(1e6+1,0);
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
        cnt[a[i]]++;
    }
    ll _mx = *max_element(all(a));
    for(ll c = _mx; c >= 1; --c) {
        ll _cnt =0 ; 
        for(ll i = c; i<= _mx; i+=c) {
            _cnt += cnt[i];
        }
        if(_cnt >= 2) {
            cout << c << "\n";
            return; 
        }
    }
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

//accepted.