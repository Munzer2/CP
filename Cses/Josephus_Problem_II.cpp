#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define ll long long
#define all(x) x.begin(), x.end()
#define pb(x) push_back(x)
using namespace std;
using namespace __gnu_pbds; 

template<class T> using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;


void debug_vector(vector<ll>& a) {
    for (auto x : a) cout << x << " ";
    cout << "\n";
    return;
}

/// this is too slow for large n , k
void solve() {
    ll n , k ; 
    cin >> n >> k; 
    set< ll >  s ; 
    for( ll i = 1 ; i <= n ; i++ ) s.insert(i) ;
    auto it = s.begin() ;
    while(s.size() >= 1) { 
        auto pos = distance(s.begin() , it);
        pos = (pos + k)%s.size();
        it = next(s.begin() , pos);
        cout << *it << " "; 
        it = s.erase(it);
    }
    return;
}

/// this is the efficient solution. Using pbds.
void solve2() {
    ll n , k ; 
    cin >> n >> k; 
    oset< ll > s; 
    for(ll i = 1; i <= n; ++i) s.insert(i);
    ll curr_pos = 0 ; 
    while(!s.empty()) { 
        curr_pos = (curr_pos + k)%s.size();
        auto it = s.find_by_order(curr_pos);  
        cout << *it << " ";
        s.erase(it);
    }
    cout << "\n"; 
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll tt = 1;
    // cin >> tt;
    while (tt--) {
        solve2();
    }
    return 0;
} 


/// solve2() is the efficient solution using pbds. Accepted.