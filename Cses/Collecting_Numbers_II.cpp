#include <bits/stdc++.h>
#define ll long long
#define all(x) x.begin(), x.end()
#define pb(x) push_back(x)
using namespace std;

void debug_vector(vector<ll> &a)
{
    for (auto x : a)
        cout << x << " ";
    cout << "\n";
    return;
}

void solve()
{
    ll n, m;
    cin >> n >> m;
    vector<ll> a(n + 1), ind(n + 1);
    for (ll i = 1; i <= n; ++i)
    {
        cin >> a[i];
        ind[a[i]] = i;
    }
    ll curr = 0;
    for (ll i = 1; i < n; ++i)
    {
        if (ind[i + 1] < ind[i])
        {
            curr++;
        }
    }
    auto ineq = [&](ll pos)->bool { 
        return (pos>=1 && pos < n && ind[pos] > ind[pos+1]); 
    }; 
    while (m--)
    {
        ll x, y;
        cin >> x >> y;
        if(x > y)swap(x,y);
        vector< ll > check; 
        auto add = [&](ll num) { 
            if(num >= 1 && num < n) { 
                check.pb(num);
            }
        };
        add(a[x]-1), add(a[x]), add(a[y]-1), add(a[y]);
        ll v1 = a[x], v2 = a[y]; 
        sort(all(check)); 
        check.erase(unique(all(check)),check.end()); 
        for(auto v : check) { 
            if(ineq(v)) curr--;
        }
        swap(a[x], a[y]); 
        ind[v2] = x, ind[v1] = y;
        for(auto v: check) {
            if(ineq(v)) curr++;
        }
        cout << curr + 1 << "\n";
    }
    return;
}

/// 2 1 4 0 3
/// 1 2 4 0 3
/// 1 2 0 4 3

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll tt = 1;
    // cin >> tt;
    while (tt--)
    {
        solve();
    }
    return 0;
}