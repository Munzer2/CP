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

ll gcd(ll a, ll b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

ll lcm(ll a, ll b) {
    return (a * b / gcd(a, b));
}

void solve() {
    ll a , b, c , m; 
    cin >> a >> b >> c >> m;
    vector < ll > d = { m/lcm(a,b), m/lcm(b,c), m/lcm(a,c), m/lcm(lcm(a,b),c) };
    ll _a1 = m/a - d[0] - d[2] + d[3], _b = m/b - d[0] - d[1] + d[3], _c = m/c - d[1] - d[2] + d[3];
    ll _a2 = d[0] + d[2] - 2*d[3], _b2 = d[0] + d[1] - 2*d[3], _c2 = d[1] + d[2] - 2*d[3];

    cout << _a1 * 6 + _a2 * 3 + d[3]*2 << " " << _b * 6 + _b2 * 3 + d[3]*2 << " " << _c * 6 + _c2 * 3 + d[3]*2 << "\n"; 
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