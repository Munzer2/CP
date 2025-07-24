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
    ll n , x ; 
    cin >> n >> x ;
    vector< ll >  a(n); 
    for(auto &x : a ) cin >> x; 
    sort(all(a)); 
    // debug_vector(a); 
    ll i = 0, j = n-1;
    ll ans = 0 ; 
    while(i <= j) {
        ans++; 
        if(a[i] + a[j] <= x) {
            i++; 
            j--; 
        }
        else {
            j--;
        }
    }
    cout << ans << "\n";
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