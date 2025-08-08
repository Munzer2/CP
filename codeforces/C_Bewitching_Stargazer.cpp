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

ll k;
vector< ll > check; 
ll cnt ; 

ll recur(ll l, ll r) {
    if(r - l + 1 < k) return 0;
    if((r - l + 1)%2 == 0) {
        ll mid = (l + r)/2;
        return recur(l, mid) + recur(mid+1, r);
    }
    else{
        ll mid = (l + r)/2;
        check.pb(mid);  
        return recur(l, mid - 1) + recur(mid + 1, r) + mid;
    }
}


ll recur2(ll n) {
    if( n < k ) return 0;
    ll ans = recur2(n/2);
    ll x = (n+1)/2;
    ll res = ans*2 + x*cnt;
    cnt *= 2;
    if(n%2) {
        cnt += 1; 
        res += x; 
    } 
    return res;
}

void solve() {
    ll n; 
    cin >> n  >> k;
    if(k == 1) {
        cout << n*(n+1)/2 << "\n"; 
        return; 
    }
    // recur(1,n);
    // sort(all(check));
    // debug_vector(check);
    cnt = 0; 
    cout << recur2(n) << "\n"; 
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll tt;
    cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}



