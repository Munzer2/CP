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
    ll n ; 
    cin >> n ; 
    string s; cin >> s;
    auto getCost = [&](string s, char c)->ll { 
        ll n = s.size();
        vector< ll > pos;
        ll curr = 0;   
        for(ll i = 0; i < n ; ++i) { 
            if(s[i] == c) { pos.pb(i-curr); curr++; } 
        }
        ll ans = 0;
        ll med = pos.size()/2;
        for(ll i = 0; i < pos.size(); ++i) { 
            ans += abs(pos[i] - pos[med]);
        } 
        return ans;
    }; 
    cout << min(getCost(s,'a'), getCost(s,'b')) << "\n";
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


//// minimize |p_i - i - L| where L is the starting
//// index. L should be median of all p_i - i.