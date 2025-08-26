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

vector< ll > primes = {2,3,5,7};

///Used inclusion-exclusion principal. Nice.
ll get(ll N) { 
    ll ans = 0; 
    for(ll i = 1 ; i < 16; ++i) {
        ll mask = i;
        ll prod = 1;  
        for(ll j = 0 ; j < primes.size(); ++j) { 
            if((1<<j) & mask) { 
                prod *= primes[j];
            }
        }
        ll check = N/prod; 
        ll cnt = __builtin_popcount(mask);
        if(cnt&1) ans += check; 
        else ans -= check;  
    }
    return N-ans; 
}

ll get_range(ll l , ll r ) { 
    return get(r) - get(l-1) ; 
}

void solve() {
    ll l , r ; 
    cin >> l >> r ;
    cout << get_range(l,r) << "\n";   
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