#include <bits/stdc++.h>
#define ll long long
using namespace std;

vector<ll> seg_tree;

void update(ll pos, ll x, ll nd, ll st, ll ed)
{
    if(pos < st || pos > ed) return;
    if(ed == st)
    {
        seg_tree[nd] = x;
        return;
    }

    ll mid = (ed + st) / 2, left_nd = 2 * nd, right_nd = 2 * nd + 1;
    update(pos, x, left_nd, st, mid);
    update(pos, x, right_nd, mid + 1, ed);
    seg_tree[nd] = seg_tree[left_nd] + seg_tree[right_nd];
}

ll sum(ll lf, ll rt, ll nd, ll st, ll ed)
{

    if(st >= lf && ed <= rt)
    {
        return seg_tree[nd];
    }
    if(ed < lf || st > rt)
    {
        return 0;
    }

    ll left_nd = 2 * nd, right_nd = 2 * nd + 1, mid = (st + ed) / 2;
    return sum(lf, rt, left_nd, st, mid) + sum(lf, rt, right_nd, mid + 1, ed);
}

int main()
{
    ll n, m;
    cin >> n >> m;

    seg_tree = vector<ll> (4 * n);

    for(int i = 0; i < n; i++)
    {
        ll x;
        cin >> x;

        update(i, x, 1, 0, n - 1);
    }

    while(m--)
    {
        ll t, x, y;
        cin >> t >> x >> y;

        if(t == 1)
        {
            update(x, y, 1, 0, n - 1);
        }
        else
        {
            cout << sum(x, y - 1, 1, 0, n - 1) << endl;
        }
    }
}
