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

using i128 = __int128_t;

vector<i128> p10;

ostream& operator<<(ostream& os, i128 val) {
    if (val == 0) return os << "0";
    string s = "";
    bool neg = val < 0;
    if (neg) val = -val;
    while (val > 0) {
        s += (val % 10) + '0';
        val /= 10;
    }
    if (neg) s += '-';
    reverse(s.begin(), s.end());
    return os << s;
}

string to_string_i128(i128 x) {
    if (x == 0) return "0";
    bool neg = x < 0; if (neg) x = -x;
    string s;
    while (x) { int d = (int)(x % 10); s.push_back('0' + d); x /= 10; }
    if (neg) s.push_back('-');
    reverse(s.begin(), s.end());
    return s;
}

i128 sum_upto(i128 num) {
    if (num < 10) return num * (num + 1) / 2;

    string s = to_string_i128(num);
    int len = (int)s.length();

    i128 ans = 0;
    if (len > 1) ans += (i128)(len - 1) * 45 * p10[len - 2];  // <-- fixed

    i128 pre = 0;
    for (int i = 0; i < len; ++i) {
        int d = s[i] - '0';
        int rem = len - 1 - i;
        int start_d = (i == 0) ? 1 : 0;
        for (int digit = start_d; digit < d; ++digit) {
            ans += (pre + digit) * p10[rem];
            if (rem > 0) ans += (i128)45 * rem * p10[rem - 1];
        }
        pre += d;
    }
    ans += pre;
    return ans;
}

void solve()
{
    ll n; 
    cin >> n;
    i128 m = n;
    int cnt = 1;
    while (true)
    {
        i128 digits = (i128)9 * p10[cnt - 1] * cnt;
        if (m <= digits)
            break;
        m -= digits;
        cnt++;
    }
    i128 start = p10[cnt - 1];
    i128 num_index = (m - 1) / cnt;
    i128 target_num = start + num_index;
    int digit_index = (int)((m - 1) % cnt);

    i128 total_sum = 0;
    if (target_num > 1)
        total_sum += sum_upto(target_num - 1);

    string t = to_string((long long)target_num);
    for (ll i = 0; i <= digit_index; ++i)
    {
        total_sum += t[i] - '0';
    }

    cout <<  total_sum << "\n";
    return;
}

//// 9 first digits, 10->99 : 90*2 second digits, 100->999: 900*3 third digits

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    p10.resize(19);
    p10[0] = 1;
    for (int i = 1; i < 19; ++i)
    {
        p10[i] = p10[i - 1] * 10;
    }
    ll tt;
    cin >> tt;
    while (tt--)
    {
        solve();
    }
    return 0;
}



///needed a lot of help . 