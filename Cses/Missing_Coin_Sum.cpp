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
    cin >> n;
    vector< ll > a(n); 
    for(auto &x : a ) cin >> x ;
    sort(all(a));
    if(a[0] != 1) {
        cout << "1\n"; 
        return; 
    }
    pair< ll, ll > m = { 1, 1 };
    for(ll i = 1; i < n; ++i) {
        ll mn = m.first + a[i];
        ll mx = m.second + a[i]; 
        if(a[i] == m.second + 1) {
            m.second = mx;
            continue; 
        }
        if(mn > m.second + 1) {
            cout << m.second + 1 << "\n"; 
            return; 
        }
        m.second = mx;
    }
    cout << m.second + 1 << "\n"; 
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


///accepted.