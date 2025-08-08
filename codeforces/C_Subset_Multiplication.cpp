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

ll lcm(ll a , ll b) { 
    return (a*b)/__gcd(a,b);
} 


void solve() {
    ll n ; 
    cin >> n ; 
    vector< ll > b(n); 
    for(auto &x : b) cin >> x;
    ll ans = -1, ans1 = 1;  
    for(ll i = 0 ; i < n-1; ++i) {
        if(b[i+1]%b[i] != 0) {
            ll g = __gcd(b[i], b[i+1]);
            ll A = b[i]/g;
            ans = (ans == -1 ? b[i] : __gcd(ans, b[i]));
            ans1 = lcm(ans1, A); 
        }
    }
    
    cout << (ans == 0 ? 1 : ans1) << "\n";
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


///accepted. Took help