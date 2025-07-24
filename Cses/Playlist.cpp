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
    map< ll,ll > mp;
    vector<ll> a(n) ;
    for (ll i = 0 ; i < n ; i++) {
        cin >> a[i] ;
        mp[a[i]]  = -1;
    }
    vector< ll > ans(n); 
    ans[0] = 1;
    mp[a[0]] = 0;
    for(ll i = 1; i < n; ++i) {
        if(a[i] == a[i-1]) {
            ans[i] = 1;
            mp[a[i]] = i ; 
        }
        else{
            if(mp[a[i]] == -1) {
                ans[i] = ans[i-1] + 1;
            }
            else {
                if(i - mp[a[i]] > ans[i-1]) ans[i] = ans[i-1] + 1 ;
                else ans[i] = i - mp[a[i]];
            }
            mp[a[i]] = i;
        }
    }
    sort(all(ans)); 
    // debug_vector(ans);
    cout << ans.back() << "\n";  
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


///accepted. A very nice solution. 