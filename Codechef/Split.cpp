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

/// so this check function is wrong. Suppose I have 011000, and I want len = 5
/// In this case,my check function ignores the three 0's after the 1's. But I can make a block with 011000 because 0000 --> 4
/// Input: 6 1 011000 -->  gives 3 using _check but it should be 4.
ll _check(string s, ll len, ll k) {
    ll cnt = 0, block = 0;
    char curr; 
    for(ll i =0 ; i < s.size(); ++i) {
        if(!cnt) { 
            cnt++; curr = s[i];
        }
        else {
            if(s[i] >= curr) {
                cnt++;
                curr = s[i];
            }
        }
        if(cnt >= len) {  cnt = 0; block++;  }
    }
    return block>=k; 
}

/// a nicer solution
ll _check2(string s, ll len ,ll k) {
    ll z = 0, c = 0, block = 0; 
    for(ll i = 0 ; i < s.size(); ++i) {
        if(s[i] == '0') z++;
        else c++;
        c = max(c,z);
        if(c >= len) {
            block++, c =0, z =0; 
        }
    }
    return block >= k;
}

void solve() {
    ll n, k ; 
    cin >> n >> k; 
    string s ; 
    cin >> s;
    ll mx= -1; 
    ll l = 1, r = n; 
    while(l <= r) {
        ll mid = (l + r)/2;
        if(_check2(s,mid,k)) {
            mx = mid; 
            l = mid+1;
        }
        else r = mid-1;
    }
    cout << max((ll)1, mx) << "\n";
    return;
}


void test() {
    string s = "10110";
    ll k = 2, len = 1;
    cout << _check(s, len,k) << "\n";
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
        // test(); 
    }
    return 0;
}


/* 
How can we solve this problem efficiently? ---> binary search on the answer.
accpeted. A good problem.
*/