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


void print_bin(ll a) {
    uint64_t mask = 1<<20;
    while(mask) { 
        if(mask&a) cout << "1"; 
        else cout << "0"; 
        mask >>= 1;
    }
    cout << "\n"; 
    return; 
}

pair< ll, ll > process(ll l, ll r) {
    uint64_t mask = (1ULL << 31);
    while(1) {
        if(!mask) break;
        if((mask & r) && (mask&l)) {
            mask >>= 1;
        }
        else if((mask & r) == 0 && (mask & l) == 0) {
            mask >>= 1;
        }
        else{
            break;
        }
    }
    mask >>= 1;
    while(mask!= 0) {
        if(mask&r) r^= mask;
        l |= mask;
        mask >>= 1;
    }
    return {l,r}; 
}


void solve() {
    ll l,r; 
    cin >> l >> r; 
    pair< ll, ll > p =  process(l,r);
    ll ans = -1;
    for(ll i = l; i <= r; ++i) {
        if(i != p.second && i != p.first) {
            ans = i; 
            break; 
        }
    }
    cout << p.first << " " << p.second << " " << ans << "\n";
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

///accepted. 
///A very nice problem about bitmasking. Maximizing a^b + b^c + c^a where l<= a,b,c <= r and a,b,c are distinct. Also r-l > 1

