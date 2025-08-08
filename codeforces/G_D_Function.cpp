#include<bits/stdc++.h>
#define ll long long
#define all(x) x.begin(), x.end()
using namespace std;


void debug_vector(vector< ll >&a){
    for(auto x : a ) cout << x  << " "  ;
    cout << "\n"; 
    return; 
}

ll gcd(ll a, ll b )
{
    if(b==0) return a ;
    return gcd(b,a%b)  ;
}

ll Mod = 1e9 + 7; 


ll Mod_exp(ll base,ll exp){
    ll ans = 1;
    while(exp > 0){
        if(exp % 2) ans = (ans*base)%Mod;
        base = (base*base)%Mod; 
        exp /=2;
    }
    return ans;
}

ll Mod_inverse(ll a,ll Mod){
    return Mod_exp(a,Mod-2);
}

void solve()
{
    ll l, r , k ; 
    cin >> l >> r >> k; 

    if(k >= 10 ){
        cout << "0\n"; 
        return;
    }
    ll poss =0 ;
    for(ll i = 1; i <= 9; ++i){
        if(k*i >= 10){
            break; 
        }
        else poss++;
    }

    /// so poss+1 = c;
    /// poss*((c^r - 1)/(c-1))*a where a is the first term.
    ll c = poss+1; 
    ll term_r = Mod_exp(c,r), term_l = (l == 0 ? 1 : Mod_exp(c,l));
    ll num = (term_r - term_l + Mod)%Mod; 
    ll inv_denum = Mod_inverse(poss,Mod);
    ll ans = (num*inv_denum)%Mod; 
    ans = (ans*poss)%Mod;
    cout << ans << "\n";  
    return;
}

int main(){
    ll tt; 
    cin >> tt; 
    while(tt--){
        solve() ;
    }
    return 0 ;  
}