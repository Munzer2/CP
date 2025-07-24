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


const ll mx = 1e18;

void compute(vector< ll > &pre){
    ll prod =1;
    for(ll i = 1; ; ++i){
        pre.push_back(prod*9*i);
        if(prod*9*i > mx) break;
        prod *= 10;
    }
    return ; 
}

ll find_digit(ll d,ll k){
    ll cnt = 0; 
    while(1){
        if(cnt == k) return (d%10); 
        cnt++;
        d /= 10; 
    }
}


void solve()
{
    ll n ; 
    cin >> n;
    vector< ll > pre;
    compute(pre);
    // debug_vector(pre);
    while(n--){
        ll k ; 
        cin >> k;
        ll cnt = 1;
        for(auto x: pre){
            if(x < k) { k-= x; cnt++; }
            else{
                break;
            }
        }
        ll prod = 1, c = cnt;
        while(--c){
            prod*=10;
        }
        ll d = prod + (k%cnt == 0 ? k/cnt -1 : k/cnt);
        cout << find_digit(d,(k%cnt ? cnt - (k%cnt) : k%cnt)) << "\n";
    }
    return; 
}

int main(){
    ll tt  = 1; 
    // cin >> tt; 
    while(tt--){
        solve() ;
    }
    return 0 ;  
}

/// accpeted.A very good problem in cses.