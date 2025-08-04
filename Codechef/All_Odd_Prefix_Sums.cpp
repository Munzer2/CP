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
    cin >> n; 
    vector< ll > a(n); 
    ll o = 0; 
    for(auto &x : a ) { 
        cin >> x;
        o += (x%2 ? 1 : 0); 
    }

    if(o == 1) cout << "Yes\n"; 
    else cout << "No\n"; 
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