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


void solve()
{
    ll n,m; 
    cin >> n >> m; 
    string s ; 
    cin >> s;
    vector< ll > inv;
    for(ll i = 1; i < n; ++i){
        if(s[i] == '0' && s[i-1] == '1') inv.push_back(i-1);
    }
    cout << "Inversions: " ;
    debug_vector(inv);
    map< ll, ll > mp;
    map< pair< ll, ll >, ll > check;
    ll ans = 0;
    ll flag=0;
    for(ll i = 0 ; i < m ; ++i){
        ll x, y; 
        cin >> x >> y;
        x--; y--;
        if(!check[{x,y}]){
            check[{x,y}] = 1;
            ll cnt = 0;
            ll c = lower_bound(all(inv),x) - inv.begin();
            ll d = upper_bound(all(inv),y) - inv.begin();
            for(ll j = c ; j < d ; ++j){
                if(inv[j] < x) break;
                if(!mp[j]) {
                    mp[j] = 1;
                    cnt++;
                }
            }
            if(!cnt) flag=1;
            ans += (cnt == 0? 0 : 1);
            cout << c << " " << d << " " << ans << "\n";
        }
    }
    cout << (flag ? ans + 1 : ans) << "\n";
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
