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

class DisjSet {
    vector<ll> rank, par;
    ll n;
public:
    DisjSet(ll n) {
        rank.resize(n, 0);
        par.resize(n);
        this->n = n;
        init();
    }

    void init() {
        for (ll i = 0; i < n; ++i) par[i] = i;
        return;
    }

    ll find(ll i) { // path compression
        if (par[i] == i) {
            return i;
        }
        ll res = find(par[i]);
        par[i] = res;
        return res;
    }

    void Union(ll x, ll y) {
        if (find(x) == find(y)) {
            return;
        }
        ll par_x = find(x);
        ll par_y = find(y);
        if (rank[par_x] < rank[par_y]) {
            par[par_x] = par_y;
        } else if (rank[par_x] > rank[par_y]) {
            par[par_y] = par_x;
        } else {
            par[par_y] = par_x;
            rank[par_x] += 1;
        }
        return;
    }
};



void solve() {
    ll n ; 
    cin >> n;
    vector< ll > a(n); 
    Disjset _dsu(n);
    for(ll i = 0; i < n; ++i) {
        cin >> a[i] ; 
    }
    for(ll i = 0 ; i < n; ++i){
        ll x = a[a[i]-1];
        ll par = _dsu.find(a[i]);
    }
    return;
}

int main() {
    ll tt;
    cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}