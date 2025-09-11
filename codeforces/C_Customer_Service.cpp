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
    vector< vector< ll >> grid(n, vector< ll > (n)), suf(n, vector< ll > (n,0)); 
    for(ll i = 0 ; i< n ; ++i ) { 
        for(ll j = 0 ;j < n; ++j) {  
            cin >> grid[i][j];
        } 
    }
    for(ll i = 0 ; i < n; ++i) { 
        ll rSum = 0; 
        for(ll j = n-1; j >= 0; --j) { 
            // suf[i][j] = (j == n-1 ? 0 : suf[i][j+1]) + grid[i][j];
            suf[i][j] = rSum; rSum += grid[i][j];   
        }
        reverse(all(suf[i]));
    }
    // for(ll i = 0 ; i < n; ++i) { 
    //     for(ll j = 0 ; j < n ; ++j) cout << suf[i][j] << ' '; 
    //     cout << '\n'; 
    // }
    // cout << "-----\n"; 
    sort(suf.begin(), suf.end()); 
    // for(ll i = 0 ; i < n; ++i) { 
    //     for(ll j = 0; j < n; ++j) cout << suf[i][j] << ' '; 
    //     cout << '\n'; 
    // }
    ll x = 0, p = n-1; 
    for(ll i = 0 ; i < n; ++i) { 
        for(ll j = p; j >= 0; --j) { 
            if(suf[j][i] == x) { 
                x++; p = j-1;  break;
            }
        }
    }
    cout << x << '\n'; 
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

// 2 3 3 ---> first column max 8, min 0, can get 2,6
// 0 1 2 ---> mex = 3