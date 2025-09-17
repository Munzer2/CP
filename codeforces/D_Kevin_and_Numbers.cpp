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

void solve() {
    ll n , m ; 
    cin >> n >> m; 
    vector< ll > a(n), b(m) ; 
    ll s = 0, s1 = 0;  
    for(auto &x : a ) { cin >> x; s+=x;  }  
    for(auto &x : b ) { cin >> x; s1+=x; } 
    if(s != s1) {  
        cout << "No\n"; return; 
    }
    multiset< ll > mul(all(a)); 
    priority_queue< ll > pq; 
    for(auto &x : b) pq.push(x);
    while(!pq.empty()) { 
        ll x = pq.top() ; pq.pop(); 
        ll y = *mul.rbegin(); 
        if(x < y) { 
            cout << "No\n"; 
            return; 
        }

        if(x == y) { 
            mul.erase(prev(mul.end()));
            continue; 
        }

        if(x == 1) { 
            cout << "No\n"; return; 
        }

        ll d = x / 2, d1 = x - d; 
        pq.push(d); pq.push(d1); 
    } 
    cout << (mul.empty() ? "Yes" : "No") << "\n"; 
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

/// accepted.

