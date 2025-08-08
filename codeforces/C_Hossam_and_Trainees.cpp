#include<bits/stdc++.h>
#define ll long long
// #define all(x) x.begin(), x.end()
#define pb(x)  push_back(x)
using namespace std;


void debug_vector(vector< ll >&a){
    for(auto x : a ) cout << x  << " "  ;
    cout << "\n"; 
    return; 
}

ll gcd(ll a, ll b){
    if(b == 0) return a;
    return gcd(b,a%b);
}

ll N = 1e5+5; 
vector< ll > vis(N,1);
void Sieve(){
    for(ll i = 4; i<N; i+=2){ 
        vis[i] = 0;
    }
    for(ll i = 3; i*i < N; i+=2){
        if(vis[i]){
            for(ll j = i*i ; j < N; j+=i+i) vis[j] = 0;
        }
    }
}

vector< ll > primes;

void gen(){
    for(ll i = 2; i < N; ++i) {
        if(vis[i]) primes.pb(i);
    }
}

vector< ll > all(N);
ll c = 1;

void pre(){
    c++;
}

void check(ll x,bool &ok){
    if(all[x] == c) {
        ok = true;
        return; 
    }
    all[x] = c;
    return; 
}

void solve()
{
    pre();
    ll n ; 
    cin >> n ; 
    vector< ll > a(n);
    bool ok = false;
    for(ll i = 0 ; i < n; ++i){
        cin >> a[i];
    }
    set< ll > big_primes;
    for(ll i = 0 ; i < n; ++i){
        if(a[i] == 1) continue;
        if(a[i] < N && vis[a[i]]){
            check(a[i],ok); 
            continue; 
        }
        if(a[i] >= N){ 
            if(big_primes.find(a[i]) != big_primes.end()){
                ok = true;
                continue;
            }
        }
        for(ll j = 0 ; j < primes.size() && primes[j]*primes[j] <= a[i]; ++j){
            if(a[i] == 1) break;
            if(a[i]%primes[j] == 0){
                check(primes[j], ok);
                while(a[i]%primes[j] == 0) a[i] /= primes[j]; 
            }
        }
        if(a[i] != 1) {
            if(a[i] < N) {
                check(a[i], ok) ; continue; 
            }
            if(big_primes.find(a[i]) != big_primes.end()) ok = true;
            else big_primes.insert(a[i]); 
        }
    }
    cout << (ok ? "YES\n" : "NO\n"); 
    return; 
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    Sieve();
    gen();
    ll tt ; 
    cin >> tt; 
    while(tt--){
        solve() ;
    }
    return 0 ;  
}
///horrible implementation. accpeted. 