#include <bits/stdc++.h>
#define ll long long
using namespace std;

vector<ll> seg_tree, lazy;

void build(ll pos, ll x, ll nd, ll st, ll ed)
{
    if(pos < st || pos > ed) return;
    if(ed == st)
    {
        seg_tree[nd] = x;
        return;
    }

    ll mid = (ed + st) / 2, left_nd = 2 * nd, right_nd = 2 * nd + 1;
    build(pos, x, left_nd, st, mid);
    build(pos, x, right_nd, mid + 1, ed);
    seg_tree[nd] = seg_tree[left_nd] + seg_tree[right_nd];
    lazy[nd] = 0;
}

void update(ll left, ll right, ll idx, ll l, ll r, ll val)
{
    if(lazy[idx] != 0){
        seg_tree[idx] += (right - left + 1) * lazy[idx];
        if(left != right)
        {
            lazy[idx * 2] += lazy[idx];
            lazy[idx * 2 + 1] += lazy[idx];
        }
        lazy[idx] = 0;
    }

    if(l > right || r < left)
    {
        return;
    }

    if(l <= left && r >= right)
    {
        seg_tree[idx] += (right - left + 1) * val;
        if(left != right)
        {
            lazy[2 * idx] += val;
            lazy[2 * idx + 1] += val;
        }
        return;
    }

    ll mid = (left + right) / 2, left_nd = 2 * idx, right_nd = 2 * idx + 1;
    update(left, mid, left_nd, l, r, val);
    update(mid + 1, right, right_nd, l, r, val);
}

ll value(ll left, ll right, ll idx, ll pos)
{
    if(lazy[idx] != 0){
        seg_tree[idx] += (right - left + 1) * lazy[idx];
        if(left != right)
        {
            lazy[idx * 2] += lazy[idx];
            lazy[idx * 2 + 1] += lazy[idx];
        }
        lazy[idx] = 0;
    }

    if(pos < left || pos > right)
    {
        return -1;
    }
    if(left == right)
    {
        return seg_tree[idx];
    }

    ll mid = (left + right) / 2, left_nd = 2 * idx, right_nd = 2 * idx + 1;

    ll x1 = value(left, mid, left_nd, pos);
    ll x2 = value(mid + 1, right, right_nd, pos);

    return max(x1, x2);
}

int main()
{
    ll n, m;
    cin >> n >> m;

    seg_tree = vector<ll> (4 * n);
    lazy = vector<ll> (4 * n);

    for(int i = 0; i < n; i++)
    {
        ll x;
        cin >> x;

        build(i, x, 1, 0, n - 1);
    }

    while(m--)
    {
        ll type, a, b, u;
        cin >> type;

        if(type == 1)
        {
            cin >> a >> b >> u;
            update(0, n - 1, 1, a - 1, b - 1, u);
        }
        else
        {
            cin >> u;
            cout << value(0, n - 1, 1, u - 1) << endl;
        }
    }

}
