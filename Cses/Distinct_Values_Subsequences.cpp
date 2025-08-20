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
ll MOD = 1e9 + 7;

void solve() {
    ll n ; 
    cin >> n ;
    vector< ll > a(n); 
    map< ll, ll > cnt; 
    for(auto &x: a ) { 
        cin >> x;
        cnt[x]++;
    }
    ll ans = 1;
    for(auto x : cnt) {
        ans = (ans * (x.second+1))%MOD;
    }
    ans--;
    cout << ans << "\n";
    
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll tt=1;
    // cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}


/// if an element occurs n times, options for element is (n+1).