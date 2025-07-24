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
    ll n, x; 
    cin >> n >> x; 
    vector< pair< ll, ll > > books(n);
    for(ll i = 0 ; i < n ; ++i) {
        cin >> books[i].first; 
    }  
    for(ll i = 0 ; i < n ; ++i) {
        cin >> books[i].second; 
    }  
    sort(all(books)); 
    vector< ll > dp(x+1, 0); 
    
    for(ll i = 0; i < n ; ++i) {
        for(ll _x = x ; _x >= books[i].first ; --_x) {
            dp[_x] = max(dp[_x - books[i].first] + books[i].second, dp[_x]); 
        }
        // for(ll _x = books[i].first ; _x <= x ; ++_x) {
        //     dp[_x] = max(dp[_x - books[i].first] + books[i].second, dp[_x]); 
        // }
        ///This won't work. Explanation below.
        // debug_vector(dp); 
    }
    // debug_vector(dp);
    cout << dp[x] << "\n"; 
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


//// when doing this, dp[10] = dp[5] + books[5].second ( which is 8) = 5 + 8 = 13
//// This happens because dp[5] = 5 is from previous iteration.
//// Doing this makes sure that dp[10] doesnt include the book with price 5 twice.
//// Because dp[5] = 5 means we can get 5 max pages with at most price of 5 from previous iteration( which calculated this keeping max price to 4).
//// If we iterated from 5 to x(which is 10), then dp[5] would be 8 before going to dp[10], so dp[10] is going to consider dp[5] + 8  as 16, taking 5 twice.
//// This would be problematic as we can't take two of the same books. 
//// By iterating from x to current price (say 5), we are making sure that each dp[j - curr_price] considers the previous iteration or old value which didnt consider the current price point yet.
//// Good problem. Accepted.

