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

struct C { 
    ll l,r, idx; 
}; 

void solve() {
    ll n; 
    cin >> n ; 
    using P = pair< ll, ll >; 
    /// use min heap.
    priority_queue< P, vector< P> , greater< P>> pq;
    vector<C> pairs(n); 
    vector< ll > ans(n);
    ll roomID = 0;
    for(ll i =0 ; i < n; ++i) { 
        cin >> pairs[i].l >> pairs[i].r;
        pairs[i].idx = i; 
    }  
    sort(all(pairs), [](const C &a, const C &b){ 
        if(a.l == b.l) return a.r < b.r; 
        return a.l < b.l; 
    });
    for(auto &x : pairs) { 
        if(!pq.empty() && pq.top().first < x.l) { 
            auto [end, room] = pq.top(); pq.pop();
            ans[x.idx] = room; 
            pq.push({x.r, room}); 
        }
        else { 
            ++roomID; 
            pq.push({x.r, roomID}); 
            ans[x.idx] = roomID; 
        }
    } 
    cout << roomID << "\n"; 
    debug_vector(ans); 
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll tt = 1;
    // cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}