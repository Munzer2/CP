#include<bits/stdc++.h>
#define ll long long
#define all(x) x.begin(), x.end()
#define pb(x) push_back(x)
using namespace std;
using P = pair< ll, ll >; 

void debug_vector(vector<ll>& a) {
    for (auto x : a) cout << x << " ";
    cout << "\n";
    return;
}
vector< ll > a;

void solve() {
    ll n;
    cin >> n; 
    a.resize(n); 
    for(auto &x : a) cin >> x;
    auto getSum = [&]()->ll { 
        ll s = 0; 
        for(ll i = 1; i <= a.size(); ++i) s += ((i&1) ? 1 : -1)*a[i-1]; 
        return s;  
    }; 
    ll sum = getSum(); 
    ll ans = sum;
    for(ll i = 0; i < n; ++i) { 
        ans = max(ans, sum + i - i%2); 
    }
    ll minEv = 1e10, minOdd = 1e10; 
    for(ll i = 0 ; i < n; ++i) { 
        if((i&1)) { 
            ans = max(ans,sum + i + 2*a[i] - minEv);
            minOdd = min(minOdd,i-2*a[i]); 
        }
        else { 
            ans = max(ans,sum + i-2*a[i] - minOdd); 
            minEv = min(minEv, i + 2*a[i]); 
        }
    }
    cout << ans << "\n";
    a.clear();
    return;
}

/// sum + 2*(a[i] - a[j]) + |i-j| is the new f. Maximize this.
/// in 0-based indexing, if current index j is odd ( in the negative protion) then : 
/// swapping with previous ith even index will give : 
/// j-i + 2*(a[j] - a[i]) -->  j+ 2*a[j] - (i+2*a[i])
/// if j is even then a[j] was in the positive portion. Then: 
/// So when we swap with ith odd --> j-i + 2*(a[i] - a[j]) ---> 
/// j-2*a[j] - ( i - 2*a[i] )
/// so keep track of min(i-2*a[i]) when i is odd
/// Also keep track of min(i+2*a[i]) when i is even


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