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
    ll n ; 
    cin >> n;  
    vector< ll > a(n); 
    for(auto &x : a ) cin >> x; 
    stack< pair< ll, ll>> st;
    for(ll i = 0; i < n ; ++i) { 
        if(!i) { 
            cout << "0 "; 
            st.push({a[i],i+1}); 
        }
        else { 
            while(!st.empty() && st.top().first >= a[i]) st.pop();
            if(!st.empty()) { 
                cout << st.top().second << " ";
            }
            else cout << "0 "; 
            st.push({a[i],i+1}); 
        }
    }
    cout << "\n";  
    return;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll tt=1;
    // cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}


///Accepted. Stack keeps track of increasing numbers always. O(n)
