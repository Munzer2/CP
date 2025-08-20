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

map< char, ll > mp;

void check(char c, ll rem, bool& ok) {
    for(char x = c+1; x <= 'Z'; ++x) {
        if(2*mp[x]-1 > rem ) {
            ok &= false;
            break;
        }
    }
    return; 
}


void solve() {
    string s ; 
    cin >> s; 
    mp.clear();
    map< ll, ll > seen;
    for(auto x : s ) { 
        mp[x]++;  
    } 
    bool ok = true; 
    for(auto x : mp) {
        if(2*x.second > s.size() + 1) ok &= false; 
    }
    if(!ok) {
        cout << "-1\n"; return; 
    }

    ll curr = 0;
    vector< char > ans(s.size()); 
    for(ll i = 0 ; i < s.size(); ++i) {
        for(char x = 'A' ; x <= 'Z' ; ++x) {
            if(i > 0 && ans[i-1] == x) { 
                continue;
            }
            if(mp[x] > 0) {
                bool ok = true;
                check(x, s.size() - i - 1, ok);
                if(ok) {
                    mp[x]--;
                    ans[i] = x;
                    break;
                }
            }
        }
    }

    for(auto x : ans) cout << x; 
    cout << "\n";
    
    
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


///Good problem. Constructive algorithm.