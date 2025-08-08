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
    string s ; 
    cin >> s;
    if(s[0] == '0' || (s.size() == 2 && s[0] == '+' && s[1] == '0')) {
        cout << "NO\n"; 
        return; 
    }
    ll n = 0, state = -1, last_char = -1; 
    bool check = true; 
    for(ll i = 0; i < s.size(); ++i) {
        if(s[i] == '+') n++;
        else if(s[i] == '-') {
            --n; 
            if(state != -1 && n < state) {
                state = n;
            }
        }
        else {
            if(s[i] == '1') {
                if(state == -1) {
                    state = n; 
                }
                else{
                    if(last_char == 0) {
                        
                    }
                    else{

                    }
                }
            }
            else{
                if(state == -1) continue;
                if(n <= 1) { check &= false; break; }
                if(n <= state) { check &= false; break; }
            }
            last_char = s[i] - '0';
        }
    }
    if(check) cout << "YES\n"; 
    else cout << "NO\n"; 
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