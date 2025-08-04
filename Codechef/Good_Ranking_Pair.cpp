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
    cout << "2\n"; 
    for(ll i = 1; i<= n; i++) {
        cout << i << " "; 
    }
    cout << "\n";
    for(ll i = n; i >= 1; i--) {
        cout << i << " "; 
    }
    cout << "\n";
    return;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll tt= 1;
    // cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}

///passed