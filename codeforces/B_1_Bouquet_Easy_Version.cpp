#include<bits/stdc++.h>
#define ll long long
#define all(x) x.begin(), x.end()
using namespace std;


void debug_vector(vector< ll >&a){
    for(auto x : a ) cout << x  << " "  ;
    cout << "\n"; 
    return; 
}


void solve()
{
    ll n , m ; 
    cin >> n >> m; 
    vector< ll > a(n); 
    for(auto &x : a ) cin >> x;
    sort(all(a));
    vector< ll > pre(n,0); pre[0] = a[0]; 
    for(ll i = 1; i < n; ++i ) pre[i] = pre[i-1] + a[i];
    ll ans = 0;
    for(ll i = 0; i< n; ++i ){
        ll low = i, high = n-1, ans_ind = i;
        while(low < high){
            ll mid = (low + high)/2; 
            if(abs(a[mid] - a[i]) <= 1 && pre[mid] - (i== 0 ? 0 : pre[i-1]) <= m){
                ans_ind = mid;
                low = mid+1;
            }
            else{
                high = mid;
            }
        }
        if(abs(a[low] - a[i]) <= 1 && pre[low] - (i == 0 ? 0 : pre[i-1]) <= m) ans_ind = low;
        if(ans_ind == i){
            ans = (a[i] <= m ? max(ans,a[i]) : ans); 
        }
        else ans = max(ans, pre[ans_ind] - (i == 0 ? 0 : pre[i-1]));
    }
    cout << ans << "\n";
    return;
}

int main(){
    ll tt ; 
    cin >> tt; 
    while(tt--){
        solve() ;
    }
    return 0 ;  
}

///accepted.