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

template <typename T>
class SegmentTree {
public: 
    vector<T> tree;
    ll n;

    SegmentTree(ll n)  {
        this->n = n;
        tree.assign(4*n, 0);
    }

    void update(ll idx, ll val, ll node, ll l , ll r) {
        if(l == r ) {
            tree[node] += val;
            return; 
        }
        ll mid = (l+r)/2; 
        if(idx <= mid) update(idx,val,2*node, l, mid); 
        else update(idx,val,2*node+1,mid+1,r);
        tree[node] = tree[2*node] + tree[2*node + 1];
    } 

    void update(ll idx, ll val) {
        update(idx, val, 1, 0, n-1);
    }

    ll query(ll ql, ll qr, ll node, ll l , ll r) {
        if(qr < l || ql > r) return 0;
        if(ql <= l && qr >= r) return tree[node];
        ll mid = (l+r)/2;
        return query(ql, qr, node*2, l, mid) + query(ql, qr, 2*node+1, mid+1, r);
    }
    ll query(ll ql, ll qr) {
        if(ql > qr) return 0;
        return query(ql, qr,1, 0, n-1);
    }

    void print( ) {
        debug_vector(tree); 
    }
};

void solve() {
    ll n ; 
    cin >> n ;
    vector< vector< ll > > ranges(n);
    for(ll i = 0; i < n; ++i) {
        ll a , b ; 
        cin >> a >> b;
        ranges[i] = {a, b, i}; 
    }
    sort(all(ranges), [](const vector< ll > &a, const vector< ll > &b) {
        if(a[0] == b[0]) return a[1] > b[1];
        return a[0] < b[0];
    }); 

    /// Coordinate compression.
    vector< ll > ends; 
    for(auto &r : ranges) ends.push_back(r[1]);
    sort(all(ends));
    ends.erase(unique(all(ends)), ends.end());

    auto get = [&](ll x ) {
        return (ll)(lower_bound(all(ends),x) - ends.begin());
    }; 

    SegmentTree<ll> seg(ends.size()), seg1(ends.size());
    vector< pair< ll, ll >> ans(n);

    for(ll i = n-1 ;i >= 0 ; --i) {
        ll pos = get(ranges[i][1]);
        ll cnt = seg.query(0,pos);
        ans[ranges[i][2]].first = cnt; 
        seg.update(pos,1);
    }

    for(ll i = 0 ; i < n ; ++i) cout << ans[i].first << " " ; 
    cout << "\n"; 

    for(ll i = 0 ;i < n ; ++i) {
        ll pos = get(ranges[i][1]); 
        ll cnt = seg1.query(pos,ends.size()-1);
        ans[ranges[i][2]].second = cnt; 
        seg1.update(pos,1);
    }
    for(ll i = 0 ; i < n ; ++i) cout << ans[i].second << " " ; 
    cout << "\n"; 
    
    return;
}



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll tt = 1;
    while (tt--) {
        solve();
    }
    return 0;
}


//// Nice solution using segment tree.