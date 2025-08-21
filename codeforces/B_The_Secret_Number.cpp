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
    ll n; 
    cin >> n ;
    ll cnt =  1;
    vector< ll > _ans; 
    for(ll i = 1; i <= 18 ; ++i) {
        ll _cnt = 0, prod = 1; 
        while(_cnt < cnt) {
            ++_cnt;
            prod *= 10; 
        }
        prod++; 
        if(n%prod == 0) {
            _ans.pb(n/prod);
        }
        cnt++;
    }
    cout << _ans.size( ) << "\n"; 
    if(_ans.empty()) {
        return; 
    }
    sort(all(_ans));
    debug_vector(_ans);
    return;
}

/// 11, 101, 1001

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