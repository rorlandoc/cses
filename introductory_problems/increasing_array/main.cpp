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

    ll x;
    cin >> x;
    ll xp = x;
    ll m = 0;

    FOR(i, 1, n)
    {
        cin >> x;
        if (x < xp)
        {
            m += (xp - x);
        }
        else
        {
            xp = x;
        }
    }

    cout << m << nl;
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