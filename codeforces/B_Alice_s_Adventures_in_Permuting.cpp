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
    ll n , b , c ; 
    cin >> n >> b >> c; 
    if(b == 0) {
        if(n <= 2) cout << ( c >= n ? n : n-1) << "\n";
        else {
            if(c >= n-2 ) {
                cout << (c >= n ? n : n-1) << "\n";
            }
            else cout << "-1\n";
        } 
        return ; 
    }
    ///find elements greater than n.
    ll cnt = (n-1 < c ? 0 : (n-c-1)/b + 1); 
    // cout << cnt << "\n"; 
    cout << n-cnt << "\n"; 
    return;
}

int main() {
    ll tt;
    cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}

///accepted.