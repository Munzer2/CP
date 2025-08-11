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
    string s ; 
    ll n ;
    cin >> n >> s;
    ll ans =0; 
    vector< ll > z(n+1,0);
    for(ll i = 1; i <= n ; ++i) {
        z[i] = z[i-1] + (s[i-1] == '0' ? 1 : 0); 
    }
    // debug_vector(z);
    ll ev = 1, odd = 0;
    for(ll i = 1; i <= n; ++i) {
        if(z[i]%2 == 0) {
            ans+= ev; ev++;
        }
        else {
            ans += odd; odd++;
        }
    }
    cout << ans << "\n";
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


/// I have to have even zeros for any string to be beautiful.

//// A beautiful solution. Needed help in solving this. 
//// passed.