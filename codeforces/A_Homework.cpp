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
    cin >> n ; 
    string a,b,c ; 
    cin >> a; 
    ll m ; 
    cin >> m ; 
    cin >> b >> c ;
    ll ind = 0;
    string e = ""; 
    for(ll i = 0 ;i < m ; ++i ) {
        if(c[i] == 'D') {
            a += b[ind++];
        }
        else {
            e+=b[ind++];
        }
    }
    reverse(all(e));
    cout << e + a << "\n"; 
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