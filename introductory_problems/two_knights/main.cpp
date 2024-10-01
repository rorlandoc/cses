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

    cout << 0 << nl;
    for (int i = 2; i <= n; i++)
    {
        ll grid_size = i * i;
        ll total_permutations = grid_size * (grid_size - 1) / 2;
        ll total_attacks = 4 * (i - 1) * (i - 2);
        cout << total_permutations - total_attacks << nl;
    }

    // Explanation
    //
    // total_permutations -> 2-combinations of i*i=g
    // g! / (2! * (g-2)!) = g * (g - 1) / 2
    //
    // Knigts attack each other in 2x3 and 3x2 sub-grids
    // For each of these sub-grids there are 2 attack possibilities
    //
    // a 2x3 sub-grid can start at row 1, another at row 2 and so on until row i-1
    //                can start at col 1, another at col 2 and so on until col i-2
    // therefore there are (i-1)*(i-2) 2x3 sub-grids
    // Equally there are (i-1)*(i-2) 3x2 sub-grids
    //
    // total_attacks = 2*n_2x3 + 2*n_3x2 = 4*(i-1)*(i-2)
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