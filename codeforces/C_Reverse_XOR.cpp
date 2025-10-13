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
    cin >> n; 
    if(!n) { 
        cout << "YES\n"; return; 
    }
    while(n%2 == 0) n/=2; 
    if(n == 1) { 
        cout << "NO\n"; return;
    }
    auto check = [&](ll n)-> ll{
        unsigned long long mask = 1;
        ll _c = n;
        while(_c>1) { 
            _c/=2; mask <<= 1;
        }
        unsigned long long mask2 = 1;  
        // cout << mask << "\n";
        while(mask > mask2) { 
            if(((mask2&n) && (mask&n)) || ((mask&n) == 0 && (mask2&n)== 0)) { 
                mask2 <<= 1; mask >>= 1;
            }
            else return 0;
        }
        if(mask == mask2 && ( (mask&n) && (mask2&n))) return 0;
        return 1;
    };
    cout << (check(n) ? "YES" : "NO") << "\n";
    return; 
}

/// so I need a palindrome, even length is ok. If odd, I need the middle element to be 0.
/// Good problem with a twist.
/// accepted.

int main() {
    FAST();
    ll tt;
    cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}