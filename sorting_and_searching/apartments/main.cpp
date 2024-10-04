#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define nl '\n'

#define FOR(i, a, b) for (int i = a; i < b; i++)
#define RFOR(i, a, b) for (int i = a; i >= b; i--)

void solve()
{
    int n, m, k;
    cin >> n;
    cin >> m;
    cin >> k;

    vector<int> desires(n);
    for (auto &d : desires)
    {
        cin >> d;
    }
    sort(desires.begin(), desires.end());

    vector<int> sizes(m);
    for (auto &s : sizes)
    {
        cin >> s;
    }
    sort(sizes.begin(), sizes.end());

    auto d = desires.begin();
    auto s = sizes.begin();
    int count = 0;
    while (d != desires.end() && s != sizes.end())
    {
        if (abs(*d - *s) <= k) // aparment size within desired range
        {
            count++;
            d++;
            s++;
        }
        else if (*d > *s + k) // smallest desire not small enough for current apartment
        {
            s++; // go to next apartment since there are no smaller desires available
        }
        else // smallest available apartment not small enough for current person
        {
            d++; // go to next person since there are no smaller apartments available
        }
    }

    cout << count << nl;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

#ifdef RC_LOCAL_EXECUTION
    int t;
    cin >> t;
    while (t--)
    {
        solve();
        cout << nl;
    }
#else
    solve();
#endif

    cerr << "Time taken: " << (float)clock() / CLOCKS_PER_SEC << "s" << nl;
    return 0;
}