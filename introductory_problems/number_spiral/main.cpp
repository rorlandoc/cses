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
    int r;
    int c;
    cin >> r;
    cin >> c;

    if (r == 1 && c == 1)
    {
        cout << 1 << nl;
        return;
    }

    ll layer = max(r, c);
    ll layer_end = layer * layer;
    ll layer_size = 2 * layer - 1;
    ll layer_start = layer_end - layer_size + 1;
    ll layer_pos;

    if (layer % 2 == 0) // reverse layer
    {
        layer_pos = (r <= c) ? r : r + layer - c;
    }
    else // normal layer
    {
        layer_pos = (c <= r) ? c : c + layer - r;
    }

    cout << layer_start + layer_pos - 1 << nl;

    // Explanation
    //
    // Layer index - L
    // Layer order - O (+ normal, - reverse)
    // Layer max   - M
    // Layer size  - S
    //
    // L O M  S   values
    // 1 + 1  1   1
    // 2 - 4  3   4  3  2
    // 3 + 9  5   5  6  7  8  9
    // 4 - 16 7   16 15 14 13 12 11 10
    //
    // Mapping of row, col to layer position
    //
    // Layer position - p
    // Grid row - r
    // Grid col - c
    //
    // L=2 (reverse order)
    // p  1 2 3
    // r  1 2 2
    // c  2 2 1
    // Mapping: p = (r < c) ? r : r + L - c
    //
    // L=3 (normal order)
    // p  1 2 3 4 5
    // r  3 3 3 2 1
    // c  1 2 3 3 3
    // Mapping: p = (c < r) ? c : c + L - r
    //
    // L=4 (reverse order)
    // p  1 2 3 4 5 6 7
    // r  1 2 3 4 4 4 4
    // c  4 4 4 4 3 2 1
    // Mapping: p = (r < c) ? r : r + L - c
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        solve();
        cout << nl;
    }

    cerr << "Time taken: " << (float)clock() / CLOCKS_PER_SEC << "s" << nl;
    return 0;
}