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

ll check(vector< ll > a) {
    sort(all(a)); 
    return a[0] == a.back(); 
}

void solve() {
    ll n;
    cin >> n;
    vector< ll > a(n);
    for(auto &x : a) cin >> x;
    if(check(a)) {
        cout << 0 << "\n"; 
        return; 
    }
    ll mn = *min_element(all(a));
    ll ans = 1e15;
    for(ll i = 0 ; i < n; ++i) {
        ans = min(ans, (n-1)*a[i]); 
    }
    ll mn_ind = -1;
    for(ll i = 0; i < n; ++i) {
        if(!i ) continue;
        if(a[i] == a[i-1]) {
        }
        else {
            if(mn_ind == -1) {
                if( i == 1) mn_ind = 1;
                else mn_ind = 0;
            }
            ans = min(ans,mn_ind * a[i-1] + (n-i)* a[i-1]);
            mn_ind = i;
        }
    }
    if(mn_ind < n-1) ans = min(ans, mn_ind * a[n-1]);
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