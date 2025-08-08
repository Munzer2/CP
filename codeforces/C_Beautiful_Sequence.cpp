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
    cin >> n ; 
    vector< ll > a(n); 
    for(auto &x : a ) cin >> x; 
    vector< vector< ll >> pre(3,vector< ll >(n,0));
    ll fs_1 = -1, ls_3 = -1;
    for(ll i = 0 ; i < n; ++i) {
        if(a[i] == 1) { fs_1 = i; break; }
    }
    for(ll i = n-1 ; i >= 0; --i) {
        if(a[i] == 3) { ls_3 = i; break; }
    }
    if(ls_3 == -1 || fs_1 == -1) {
        cout << "0\n"; 
        return;
    }
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