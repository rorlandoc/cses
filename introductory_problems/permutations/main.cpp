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

    if (n == 1)
    {
        cout << n << nl;
        return;
    }

    if (n <= 3)
    {
        cout << "NO SOLUTION" << nl;
        return;
    }

    int m1 = n / 2;
    int m2;
    if (n % 2 == 0)
    {
        m2 = m1;
    }
    else
    {
        m2 = m1 + 1;
    }

    FOR(i, 1, m1 + 1)
    {
        cout << i * 2 << ' ';
    }
    FOR(i, 1, m2 + 1)
    {
        cout << i * 2 - 1 << ' ';
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