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

vector< ll > a;

void solve() {
    ll n, k; 
    cin >> n >> k; 
    a.resize(n);
    map< ll, ll > freq; 
    for(auto &x : a )  
        { cin >> x ; freq[x]++; }   
    auto getmex = [&]()->ll { 
        sort(all(a));
        map< ll, ll > vis; 
        ll ans = 0;
        for(auto &x : a) {
            if(vis[x]) continue;
            vis[x] = 1; 
            if(x == ans) ans++;
        }
        return ans; 
    }; 
    ll mex = getmex(), cnt = 0, ans = 0, mn = mex;
    vector< ll > left; 
    for(auto &x : freq) { 
        if(x.first < mex && x.second == 1) { left.pb(x.first); ans += x.first; }
        else { 
            cnt += x.second; 
            if(x.first < mex) mn = min(mn,x.first);
        }
    }
    if(k == 1) { cout << ans + mex*cnt << "\n"; a.clear(); return; } 
    if(cnt == 1) { cout << ans + mex << "\n"; a.clear(); return; }
    if(mn == mex) {
        cout << (k%2 ? mex : mex+1)*cnt + ans << "\n";  
        a.clear();
        return; 
    }
    for(auto &x : left) if(x > mn) { ans -= x; cnt++; }
    cout << ans + (k%2 ? mn+1 : mn)*cnt << "\n"; 
    a.clear(); 
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll tt;
    cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}


/// 0 1 3| 2 2 6 7 ---> 0 1 3 | 4 4 4 4 ( k = 1 ) mn = 2, so mex = 2 ---> 0 1 | 3 4 4 4 4 --> 0 1 | 2 2 2 2 2 ( k = 2) 
/// accepted. Solve not super space efficient.

