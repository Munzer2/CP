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


void print_set(multiset< ll > &s) {
    for(auto x : s ) cout << x << " "; 
    cout << "\n"; 
    return; 
}


void solve() {
    ll n , m ; 
    cin >> n >> m;
    multiset< ll > s; 
    for(ll i = 0; i < n; ++i) {
        ll x ; cin >> x; 
        s.insert(x);
    }
    for(ll i = 0 ; i < m; ++i) {
        ll x ; 
        cin >> x; 
        auto it = s.upper_bound(x);
        // print_set(s);  
        if(it == s.begin()) {
            cout << "-1\n"; 
        }
        else{
            it--; 
            cout << *it << "\n";
            s.erase(it);
        }
    }
    return;
}

void check() {
    vector< ll > c = {1,2,3,7};
    ll ind1 = lower_bound(all(c),8) - c.begin();
    ll ind2 = upper_bound(all(c), 8)  -c.begin();
    cout << ind1 << "  " << ind2 << "\n"; 
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
        // check(); 
    }
    return 0;
}


///accepted.