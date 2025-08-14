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
    vector< ll > a(n), b(n); 
    for(auto &x : a ) cin >> x;
    for(auto &x : b) cin >> x;  
    if(b[n-1] != a[n-1]) {
        cout << "NO\n";
        return; 
    }
    ll curr = b[n-1];
    bool ok = true;
    for(ll i = n-2 ; i >= 0 ; --i) {
        if(b[i] == a[i]) {
            curr = b[i];
            continue; 
        }
        if(b[i] == (curr ^ a[i]) || b[i] == (a[i]^ a[i+1])) {
            curr = b[i]; 
        }
        else {
            ok = false; break;
        }
    }
    cout << (ok ? "YES\n": "NO\n"); 
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