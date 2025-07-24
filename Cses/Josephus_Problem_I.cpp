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

void solve() {
    ll n; 
    cin >> n;
    vector< ll > a(n); 
    for( ll i = 0; i < n; i++) {
        a[i] = i+1; 
    }
    vector< ll > vis(n,1);
    ll cnt = 0, ind = 0, tot = 0;
    while(1) {
        if(!vis[ind]) {
            ind = (ind + 1)%n; 
            continue; 
        }
        if(!cnt) {
            cnt++;
        }
        else{
            cnt = 0;
            cout << a[ind] << " ";
            vis[ind] = 0;
            tot++;  
        }
        ind = (ind + 1)%n;
        if(tot == n) break; 
    } 
    cout << endl; 
    return;
}


void solve3() {
    ll n ; 
    cin >> n ;
    queue< ll > q ; 
    for(ll i = 1; i <= n; ++i) q.push(i);
    ll f = 0;
    while(!q.empty()) {
        ll _n = q.front();
        q.pop(); 
        if(!f) q.push(_n); 
        else { 
            cout << _n << " "; 
        }
        f ^= 1;
    } 
    cout << endl; 
    return; 
}

///copied from another user named beijik. Nice one.
void solve2() {
    ll n;
    cin >> n;
    vector< ll > nxt(n+1); 
    for (ll i=1; i<=n; ++i) {
        nxt[i] = i+1;
    }
    nxt[n] = 1;
 
    ll i = 1;
    for (; n>1; --n) {
        // cout << nxt[i] << ' ';
        i = nxt[i] = nxt[nxt[i]];
        debug_vector(nxt);
    }
    // cout << i << endl;
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll tt = 1;
    // cin >> tt;
    while (tt--) {
        solve3();
    }
    return 0;
}