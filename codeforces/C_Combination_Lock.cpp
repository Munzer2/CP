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
    if(n%2 == 0) {
        cout << "-1\n" ; 
        return;
    }
    map< ll, ll > mp;
    vector< ll > ans(n);
    ans[0] = 1;
    ll cnt = n-1;
    for(ll i = 2; i <= n; ++i) {
        mp[i] = cnt; 
        cnt--;
    }
    for(ll i = 2; i <= n; ++i) {
        ll ind = (i - mp[i] + n)%n;
        if(!ind) ind+=n;
        ans[ind-1] = i;
    }
    debug_vector(ans); 
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

///accepted.