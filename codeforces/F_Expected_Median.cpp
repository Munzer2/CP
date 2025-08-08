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


ll Mod = 1e9 + 7;

ll power(ll x, ll y){
    ll res = 1;
    while(y>0){
        if(y%2){
            res = (res*x)%Mod;
        }
        y /= 2;
        x = (x*x)%Mod;
    }
    return res;
}



ll calc(ll n, ll r){
    ll num = 1, denum = 1;
    for(ll i = 0; i < r; ++i){
        num = (num*(n-i))%Mod;
        denum = (denum*(i+1))%Mod;
    }
    denum = power(denum, Mod-2);
    return (num*denum)%Mod;
}


ll calc2(ll n, ll r, vector< ll >&facts){
    ll num = facts[n];
    ll d = (facts[n-r]*facts[r])%Mod;
    d = power(d, Mod-2); 
    return (d* num)%Mod;
}


void update(vector< ll > &facts,ll cnt){
    for(ll i = 1; i <= cnt; ++i){
        facts[i] = (facts[i-1]*i)%Mod; 
    }
    return; 
}


void solve()
{
    ll n,k; 
    cin >> n >> k; 
    vector< ll > a(n); 
    ll cnt =0;
    for(auto &x : a ) {
        cin >> x; 
        if(x == 1) cnt++;
    }
    vector< ll > facts(max(cnt,n-cnt)+1,1);
    update(facts,max(cnt, n-cnt));
    ll ans = 0;
    for(ll i = k; i >= k/2+1; --i){
        if(i <= cnt && k-i <= n-cnt){
            ll z = n - cnt;
            ll c = calc2(cnt,i,facts);
            ll d = calc2(z,k-i,facts);
            ans = (ans + (c*d)%Mod)%Mod;
        }
    }
    cout << ans << "\n";
    return;
}

int main(){
    ll tt ; 
    cin >> tt; 
    while(tt--){
        solve() ;
    }
    return 0 ;  
}


///accepted.