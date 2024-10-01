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
    int n;
    cin >> n;

    vector<int> odds;
    vector<int> evens;

    int sum_odds = 0;
    int sum_evens = 0;
    FOR(i, 1, n + 1)
    {
        if (i % 2 == 0)
        {
            sum_evens += i;
            evens.pb(i);
        }
        else
        {
            sum_odds += i;
            odds.pb(i);
        }
    }

    int diff = abs(sum_odds - sum_evens);
    if (diff == 0)
    {
        cout << "YES" << nl;
        cout << odds.size() << nl;
        for_each(odds.begin(), odds.end(), [](int v)
                 { cout << v << " "; });
        cout << nl;
        cout << evens.size() << nl;
        for_each(evens.begin(), evens.end(), [](int v)
                 { cout << v << " "; });
    }
    else if (diff % 2 == 0)
    {
        FOR(i, 0, diff / 2)
        {
            if (sum_odds > sum_evens)
            {
                int temp = odds[i + 1];
                odds[i + 1] = evens[i];
                evens[i] = temp;
            }
            else if (sum_evens > sum_odds)
            {
                int temp = odds[i];
                odds[i] = evens[i];
                evens[i] = temp;
            }
        }
        cout << "YES" << nl;
        cout << odds.size() << nl;
        for_each(odds.begin(), odds.end(), [](int v)
                 { cout << v << " "; });
        cout << nl;
        cout << evens.size() << nl;
        for_each(evens.begin(), evens.end(), [](int v)
                 { cout << v << " "; });
    }
    else
    {
        cout << "NO" << nl;
    }
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