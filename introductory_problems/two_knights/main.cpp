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

ll number_of_knight_attacks(ll row, ll col, ll grid_size)
{
    ll attacks = 0;
    if ((row + 2) <= grid_size && (col + 1) <= grid_size)
        attacks++;
    if ((row + 1) <= grid_size && (col + 2) <= grid_size)
        attacks++;
    if ((row - 1) >= 1 && (col + 2) <= grid_size)
        attacks++;
    if ((row - 2) >= 1 && (col + 1) <= grid_size)
        attacks++;
    if ((row + 2) <= grid_size && (col - 1) >= 1)
        attacks++;
    if ((row + 1) <= grid_size && (col - 2) >= 1)
        attacks++;
    if ((row - 1) >= 1 && (col - 2) >= 1)
        attacks++;
    if ((row - 2) >= 1 && (col - 1) >= 1)
        attacks++;
    return attacks;
}

void solve()
{
    int n;
    cin >> n;

    cout << 0 << nl;
    for (int i = 2; i <= n; i++)
    {
        ll grid_size = i * i;
        ll half_grid_size = i / 2;
        ll total_permutations = grid_size * (grid_size - 1) / 2;
        ll total_attacks = 0;
        ll total_attacks_center = 0;
        for (ll r = 1; r <= half_grid_size; r++)
        {
            for (ll c = 1; c <= half_grid_size; c++)
            {
                total_attacks += number_of_knight_attacks(r, c, i);
            }
            if ((i % 2 != 0)) // handle middle cross of odd grid
            {
                total_attacks += number_of_knight_attacks(r, half_grid_size + 1, i);
            }
        }
        if (i % 2 != 0) // handle middle square of odd grid
        {
            total_attacks_center += number_of_knight_attacks(half_grid_size + 1, half_grid_size + 1, i);
        }
        total_attacks = 2 * total_attacks + total_attacks_center / 2;
        cout << total_permutations - total_attacks << nl;
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