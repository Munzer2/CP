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
    ll n, k ; 
    cin >> n >> k;
    map< ll, ll > mp; 
    for(ll i = 0; i < n; ++i) {
        ll x ; 
        cin >> x; 
        mp[x]++;
    }
    vector< ll > check;
    for(auto x : mp) check.pb(x.second); 
    sort(all(check));
    ll sz = check.size(), i;  
    for(i = 0; i < sz-1; ++i) {
        if(check[i] > k) {
            cout << sz - i << "\n"; 
            return;
        }
        k-= check[i];
        check[sz-1] += check[i];
    }
    cout << sz - i << "\n"; 
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