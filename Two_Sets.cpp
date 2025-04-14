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

vector< vector< ll >> ans;

void parse(ll n) {
    ll curr = 1; 
    if(n%2 == 0) {
        ans[0].pb(1);
        for(ll i = 2; i <= n; i+=2) {
            if(i == n) { ans[curr].pb(i); break;  }
            ans[curr].pb(i); ans[curr].pb(i+1);
            curr = (curr + 1)%2;
        }
    }
    else {
        for(ll i = 1; i <= n; i+=2) {
            if(i == n) {
                ans[curr].pb(i) ; break; 
            }
            ans[curr].pb(i); 
            ans[curr].pb(i+1);
            curr = (curr + 1)%2;
        }
    }
    return; 
}

void solve() {
    ll n;
    cin >> n ;
    ll d = (n%2 ? (n+1)/2 : n/2); 
    if(d%2) {
        cout << "NO\n"; 
        return;
    }
    ans.resize(2);
    cout << "YES\n";
    ll curr = 0;
    parse(n);
    for(ll i = 0; i < 2; ++i ) {
        cout << ans[i].size() << "\n"; 
        debug_vector(ans[i]); 
    }
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