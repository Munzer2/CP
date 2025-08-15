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
    vector< vector< ll > > ranges(n);
    for(ll i = 0; i < n; ++i) {
        ll a , b ; 
        cin >> a >> b;
        ranges[i] = {a, b, i}; 
    }
    sort(all(ranges), [](const vector< ll > &a, const vector< ll > &b) {
        if(a[0] == b[0]) return a[1] > b[1];
        return a[0] < b[0];
    });
    vector< pair< ll, ll > > ans(n); 
    ll max_end = -1, min_end = LLONG_MAX;
    for(ll i = 0 ; i< n ; ++i) { 
        ans[ranges[i][2]].second = (max_end >= ranges[i][1] ? 1 : 0);
        max_end = max(max_end, ranges[i][1]);
    }
    for(ll i = n-1 ; i>= 0 ; --i) {
        ans[ranges[i][2]].first = (min_end <= ranges[i][1] ? 1 : 0);
        min_end = min(min_end, ranges[i][1]);
    }
    for(ll i = 0 ;i < n ; ++i) cout << ans[i].first << " "; 
    cout << endl; 
    for(ll i = 0 ; i < n; ++i) cout << ans[i].second << " "; 
    cout << endl;  
    return;
}

//// How to check if one range is nested in another ?

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