#include<bits/stdc++.h>
#define ll long long
#define all(x) x.begin(), x.end()
#define pb(x) push_back(x) 
#define fs first
#define sc second
using namespace std;

void debug_vector(vector<ll>& a) {
    for (auto x : a) cout << x << " ";
    cout << "\n";
    return;
}

void solve() {
    ll k , a , b , x , y; 
    cin >> k >> a >> b >> x >> y; 
    if(x > y) {
        swap(x, y);
        swap(a, b);
    }

    ll ans = 0;

    if(k >= a) {
        ans += (k - a + x)/x ; 
        k -= ans *x; 
    }

    if(k >= b) {
        ans += (k - b + y)/y;
        k -=  ans*y; 
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