#include<bits/stdc++.h>
#define ll long long
#define all(x) x.begin(), x.end()
#define pb(x)  push_back(x)
using namespace std;


void debug_vector(vector< ll >&a){
    for(auto x : a ) cout << x  << " "  ;
    cout << "\n"; 
    return; 
}


ll N = 3e5+1;
vector< ll > a(N);
vector< ll > check(N,1);


void sieve(){
    for(ll i = 4; i <= N; i+=2) check[i] = 0;
    for(ll i = 3; i*i <= N ; i+=2) {
        for(ll j = i*i; j <= N; j+=i+i) check[j] = 0;
    }
    return ;  
}

ll factors(ll n){ 
    ll cnt = 0; 
    ll d = n;
    for(ll i = 2;  i <= d; ++i) {
        if(check[i] && n%i == 0) {
            while(n%i == 0) { cnt++; n/= i;}
        }
        if(n == 1) break;
    }
    return cnt;
}


void solve()
{
    ll n ; 
    cin >> n ; 
    vector< ll > cnts(n);
    for(ll i = 0 ; i < n ;  ++i) {
        cin >> a[i] ; 
        if(check[a[i]]) cnts[i] = 1;
        else cnts[i] = factors(a[i]);
    } 
    ll s = 0 ; 
    for(auto c : cnts ) s += c ;
    if(s%2 ) cout << "Anna\n";
    else{
        ll e = 0;  
        for(auto c : cnts ) e += (c%2 == 0) ; 
        if(e%2) cout << "Anna\n" ; 
        else cout << "Bruno\n"; 
    }
    return;
}

int main(){
    ll tt =1; 
    sieve();
    // cin >> tt; 
    while(tt--){
        solve() ;
    }
    return 0 ;  
}
