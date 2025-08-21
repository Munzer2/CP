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
    cin >> n;
    ll prod = 1, cnt = 0;  
    while(1) {
        if(prod*3 > n) break;
        prod *= 3; 
        cnt++;
    }
    ll ans = 0; 
    for(ll i = cnt; i >= 0 ; --i) { 
        ll p = n/prod;
        ll d = prod*3 + (i*(prod/3));
        ans += (p*d);
        n-= (p*prod);
        prod /= 3; 
    }
    cout << ans << "\n";
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

///  3^x for 3^x+1 + x*3^x-1, 0, 1, 2, 10, 11, 12, 20, 21, 22
/// 8 = 3 + 3 + 1 + 1