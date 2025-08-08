#include<bits/stdc++.h>
#define ll long long
#define all(x) x.begin(), x.end()
using namespace std;


void debug_vector(vector< ll >&a){
    for(auto x : a ) cout << x  << " "  ;
    cout << "\n"; 
    return; 
}

ll gcd(ll a, ll b )
{
    if(b==0) return a ;
    return gcd(b,a%b)  ;
}

void find_divs(ll n, vector< ll > &divs) {
    for(ll i = 1; i*i <= n; ++i){
        if(n%i == 0){
            if(n == i*i){
                divs.push_back(i); 
            }
            else{
                divs.push_back(i); 
                divs.push_back(n/i);  
            }
        } 
    }
    return; 
}


void print(string s, ll div, map< ll, vector< ll >> &ind){
    vector< ll > vis(26,0);
    for(ll i = 1; i <= 26; ++i){
        if(!vis[i]){
            if(ind[i].size() == div) continue;
            // if(ind[i].size() > div)
            
        }
    }
}

void solve()
{
    ll n; 
    cin >> n; 
    string s; 
    cin >> s;
    vector< ll > divs;
    find_divs(n,divs);
    sort(all(divs)); 
    map< ll, ll > mp;
    map< ll, vector< ll >> ind;
    for(ll i = 0 ; i < n; ++i ){
        mp[s[i]-'a']++; ind[s[i] - 'a'].push_back(i);
    }
    ll _ans = 1e15, ans_div;
    for(auto div : divs){
        ll ans = 0, check = 1; 
        vector< ll > vis(26,0);
        for(ll i = 1; i <= 26; ++i){
            if(!mp[i] || vis[i]) continue; 
            if(mp[i] < div){ 
                ll d = div - mp[i],check2 = 0;
                for(ll j = 1; j <= 26; ++j){
                    if(j != i && mp[j] == d && !vis[j]){
                        ans += min(d,mp[i]);
                        vis[i] = 1; 
                        vis[j] = 1; 
                        check2 = 1;
                        break ; 
                    }
                }
                // cout << "here: " << div << " " << d << "\n";
                // cout << ans << "\n";
                if(!check2){
                    check = 0; 
                    break;
                } 
            }
            else{
                if(mp[i] > div){
                    if(mp[i]%div == 0){
                        ans += (mp[i]-div);
                        vis[i] = 1;
                    }
                    else{ /// not possible in this case;
                        check = 0; 
                        break;
                    }
                }
            }
        }
        if(check){
            ans_div = div;
            _ans = min(_ans,ans);
        }
    }
    cout << _ans << "\n";
    print(s,ans_div,ind);
    return;
}

int main(){
    ll tt; 
    cin >> tt; 
    while(tt--){
        solve() ;
    }
    return 0 ;  
}