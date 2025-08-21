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
    ll n , m , k ; 
    cin >> n >> m >> k;
    vector< ll > des(n), app(m); 
    for(auto &x : des) cin >> x; 
    for(auto &x : app) cin >> x; 
    vector< ll > vis(m); 
    sort(all(des)); sort(all(app));
    ll cnt = 0; 
    ll i = 0 , j = 0; 
    while(1) {
        if(abs(des[j] - app[i]) <= k) {
            cnt++; ++i ; ++j; 
        }
        else {
            if(app[i] > des[j]) ++j; 
            else ++i; 
        }
        if(i >= m || j >= n) break; 
    }
    cout << cnt << "\n";
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