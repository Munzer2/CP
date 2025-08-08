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
    vector< ll > a(n) ;
    map< ll, ll > mp;
    for(auto &x : a ) { cin >> x; mp[x]++; } 
    sort(all(a));
    if(a[0] == a[3]) {
        for(ll i = 0; i < 4; ++i) cout << a[i] << " ";
        cout << "\n";  
        return; 
    }
    bool ans = true;
    for(auto x : mp) {
        ans &= (x.second == 1);
    }
    if(ans) {
        cout << "-1\n"; 
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