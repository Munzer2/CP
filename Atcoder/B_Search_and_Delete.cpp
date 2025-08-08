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
    ll n,m; 
    cin >> n >> m; 
    vector< ll > b(m);
    multiset< ll > a; 
    for(ll i = 0 ; i < n; i++) {
        ll x ; cin >> x; 
        a.insert(x);
    }
    for(auto &x : b ) cin >> x;
    for(auto x: b) {
        if(a.find(x) != a.end()) { 
            a.erase(a.find(x));
        }
    } 

    for(auto x : a) {
        cout << x << " ";
    }
    cout << "\n";
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


//pased.