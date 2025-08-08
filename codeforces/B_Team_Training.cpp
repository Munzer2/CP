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
    ll n ,x ; 
    cin >> n >> x; 
    vector< ll > a(n);
    for(auto &x : a) cin >> x ;
    sort(all(a)); 
    reverse(all(a));
    ll cnt = 1, ans = 0 ;
    for(ll i = 0 ;i < n; ++i) {
        if(cnt*a[i] >= x ) {
            ans++;
            cnt = 1;
        }
        else cnt++;  
    } 
    cout << ans << "\n"; 
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