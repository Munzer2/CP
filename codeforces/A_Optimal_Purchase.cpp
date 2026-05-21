#include<bits/stdc++.h>
#define ll long long
#define all(x) x.begin(), x.end()
#define pb(x) push_back(x)
#define FAST() ios::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

void debug_vector(vector<ll>& a) {
    for (auto x : a) cout << x << " ";
    cout << "\n";
    return;
}

void solve() {
    ll n, a , b ; 
    cin >> n >> a >> b;
    if(3 * a < b ) { 
        cout << n * a << "\n";
    } 
    else { 
        if( n < 3 ) {
            cout << min(b, n*a) << "\n";
            return; 
        }
        ll ans = (( n- (n % 3) )/3) * b + min((n%3)*a, b);
        cout << ans << "\n";
    }
    return; 
}

int main() {
    FAST();
    ll tt;
    cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}

/// done