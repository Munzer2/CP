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

ll N = 1e7; 
vector< ll > primes(N+1,1);

void sieve() {
    for(ll i = 2; i*i <= N ; i++) {
        if(primes[i]) {
            for(ll j = i*i; j <= N; j+=i) {
                primes[j] = 0;
            }
        }
    }
}

void solve() {
    ll n ;
    cin >> n ; 
    ll ans =0 ;
    ll prime_cnt = 0;
    for(ll i = 2; i <= n; ++i) {
        if(primes[i] == 1) {
            ans += (n/i); 
        }
         
    }
    cout << ans << "\n"; 
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll tt;
    cin >> tt;
    sieve();
    while (tt--) {
        solve();
    }
    return 0;
}

//accepted.