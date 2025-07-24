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
ll N= 1e3;
vector< ll > primes(N+1,0);

void sieve() {
    for(ll i = 2; i*i <= N; ++i) {
        if(primes[i]) continue; 
        for(ll j = i*i ; j <= N; j+=i) {
            primes[j] = 1;
        }
    }
}

ll count_div(ll n) {
    ll ans = 1;
    for(ll i = 2; i*i <= n ; ++i) {
        if(primes[i]) continue;
        ll cnt = 0; 
        while(n%i == 0) {
            n/=i;
            cnt++;
        }
        ans *= (cnt+1);
        if(n == 1) break;
    }
    if(n > 1) ans *= 2; 
    return ans; 
}

void solve() {
    ll x ; 
    cin >> x; 
    cout << count_div(x) << "\n"; 
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    sieve();
    ll tt;
    cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}

///accepted. 