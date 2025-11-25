#include<bits/stdc++.h>
#define ll long long
#define all(x) x.begin(), x.end()
#define pb(x) push_back(x)
#define FAST() ios::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

void debug_vector(vector<ll>& a) {
    for (auto x : a) cout << x << " ";
    cout << "\n";
    return;
}

class DisjSet {
    public:
    vector<ll> rank, par;
    ll n;
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
    cin >> n ;
    vector< ll > a(n); 
    map< ll, ll > ind; 
    for(ll i =0 ; i < n ; ++i) {
        cin >> a[i]; 
        ind[a[i]] = i; 
    }
    stack< ll > pending; 

    ll curr_root = a[0]; 
    for(ll i = 1 ; i < n ; ++i) { 
        if(a[i] > curr_root) { 
            if(a[i] > curr_root) { /// then this node might act as parent for previous roots. 
                while(!pending.empty() && pending.top() < a[i]) { 
                    pending.pop();
                }
            }
        }
        else { 
            pending.push(curr_root); curr_root = a[i];
        }
    }

    if(pending.empty()) cout << "Yes\n"; 
    else cout << "No\n";
    return; 
}


int main() {
    FAST();
    ll tt;
    cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}



