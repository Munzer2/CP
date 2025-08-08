#include<bits/stdc++.h>
#define ll long long
#define all(x) x.begin(), x.end()
#define pb(x) push_back(x)
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


ll check(ll strt,vector< ll > pre,ll lim){
    ll low = strt + 1, high = pre.size()-1;
    ll comp = (strt == -1 ? 0 : pre[strt]); 
    while(low < high){
        ll mid = (low + high)/2; 
        if(pre[mid]- comp >= lim) high = mid; 
        else low = mid + 1;
    }
    if(low < pre.size() &&  pre[low] - comp < lim) low++; 
    return low; 
}


void func(vector< vector< ll >> pre, ll tot, map< ll, pair< ll, ll> >&mp){
    ll n = pre[0].size(); 
    for(ll i = 0 ; i < 3; ++i){
        ll ind = check(-1,pre[i],tot);
        if(ind < n-1){
            ll ind1 = check(ind,pre[(i+1)%3],tot), ind2 = check(ind,pre[(i+2)%3],tot); 
            if(ind1 < n-1){
                if(pre[(i+2)%3][n-1] - pre[(i+2)%3][ind1] >= tot){
                    mp[i] = {0,ind};  
                    mp[(i+1)%3] = {ind+1,ind1}; 
                    mp[(i+2)%3] = {ind1 + 1,n-1};
                    break ;  
                }
            }
            if(ind2 < n-1){
                if(pre[(i+1)%3][n-1] - pre[(i+1)%3][ind2] >= tot){
                    mp[i] = {0, ind} ;  
                    mp[(i+2)%3] = {ind+1,ind2};
                    mp[(i+1)%3] = {ind2+1,n-1};  
                    break ;  
                } 
            }
        }
    }
}


void solve()
{
    ll n ; 
    cin >> n; 
    vector< vector< ll > > a(3,vector< ll > (n));
    for(ll i = 0 ; i < 3; i++){
        for(ll j = 0; j < n; ++j) cin >>a[i][j];
    }
    vector< vector< ll >> pre(3,vector< ll >(n,0));
    for(ll i = 0 ; i < 3; ++i){
        for(ll j = 0 ; j < n; ++j) pre[i][j] = (!j ? a[i][j] : pre[i][j-1] + a[i][j]);
    }
    ll tot = pre[0][n-1];
    tot = (tot%3 ? tot/3 + 1 : tot/3);
    map< ll, pair<ll, ll > > mp; 
    func(pre,tot,mp);
    if(mp[0].first == mp[1].first || mp[1].first == mp[2].first) cout << "-1\n"; 
    else{
        for(ll i = 0; i < 3;++i){
            cout << mp[i].first + 1 << " " << mp[i].second + 1 << " "; 
        }
        cout << endl;
    }
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

///accepted.