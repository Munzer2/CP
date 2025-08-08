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


void init(map< ll, ll > &ind, vector< ll > b){
    for(ll i = 0 ; i < b.size(); ++i){
        ind[b[i]] = 0;
    }
    return ; 
}

void solve()
{
    ll n ; 
    cin >> n; 
    vector< ll > a(n) , b(n);
    map< ll, vector< ll >>  mp; 
    map< ll, ll > ind; 
    for(auto &x : a) cin >> x; 
    for(ll i = 0; i < n; ++i) {
        cin >> b[i]; 
        mp[b[i]].pb(i);
    } 
    ll mx = *max_element(all(a));
    ll mn = *min_element(all(b));
    init(ind,b); 
    bool ok2 = false; 
    for(ll i = 2; i <= mx+mn; ++i){
        // cout << "I : "  << i << "\n";
        bool ok = true; 
        vector< ll > ans1, ans2;
        for(ll j = 0;  j< n; ++j){
            ll targ = i - a[j];
            ok &= (targ > 0 && mp[targ].size() > 0 && ind[targ] < mp[targ].size());
            // cout << targ  << " " << ind[targ] << "\n"; 
            if(!ok) break; 
            else{
                ans1.push_back(a[j]); ans2.push_back(targ); ind[targ]++;
            } 
        }
        if(!ok) init(ind,b);
        else{
            ok2 = true; 
            debug_vector(ans1); debug_vector(ans2);
            break;
        }
    }
    if(!ok2) cout << "-1\n";
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