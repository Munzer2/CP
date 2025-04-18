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


void set_print(multiset< ll > &s ) {
    for(auto c : s ) cout << c << " "; 
    cout << "\n"; 
}

void solve() {
    ll n , q ; 
    cin >> n >> q;
    multiset< ll > s, ans; 
    s.insert(0); 
    s.insert(n);    
    while(q--) {
        ll x ; 
        cin >> x;
        auto it = s.upper_bound(x);
        ll d = *it;
        --it;
        ll e = *it;
        auto found = ans.find(d-e); 
        if(found != ans.end()) {
            ans.erase(found); 
        }
        ans.insert(d-x); 
        ans.insert(x-e);
        // set_print(ans);
        cout << *ans.rbegin() << " ";  
        s.insert(x); 
    }
    cout << endl; 
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