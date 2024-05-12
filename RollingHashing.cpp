#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll add(ll a, ll b, ll mod)
{
    ll res = (a + b) % mod;
    if(res < 0) res += mod;
    return res;
}

ll mul(ll a, ll b, ll mod)
{
    ll res = (a * b) % mod;
    if(res < 0) res += mod;
    return res;
}

ll power(ll a, ll b, ll mod)
{
    ll res = 1;
    while(b)
    {
        if(b % 2) res = mul(res, a, mod);
        a = mul(a, a, mod);
        b /= 2;
    }
    return res;
}

ll N = 1000001, mod1 = 1e9 + 7, mod2 = 1e9 + 9;
ll base1 = 65, base2 = 65;
vector<pair<ll, ll> > pw(N), inv(N), hsh;

void precalc()
{

    pw[0].first = 1;
    pw[0].second = 1;

    for(int i = 1; i < N; i++)
    {
        pw[i].first = mul(pw[i - 1].first, base1, mod1);
        pw[i].second = mul(pw[i - 1].second, base2, mod2);
    }

    ll pw_inv1 = power(base1, mod1 - 2, mod1);
    ll pw_inv2 = power(base2, mod2 - 2, mod2);

    inv[0].first = 1;
    inv[0].second = 1;

    for(int i = 1; i < N; i++)
    {
        inv[i].first = mul(inv[i - 1].first, pw_inv1, mod1);
        inv[i].second = mul(inv[i - 1].second, pw_inv2, mod2);
    }
}

void build(string s)
{
    ll n = s.size();

     hsh.resize(n);

    for(int i = 0; i < n; i++)
    {
        hsh[i].first = add((i == 0) ? 0 : hsh[i - 1].first, mul(pw[i].first, s[i] - 'a' + 1, mod1), mod1);
        hsh[i].second = add((i == 0) ? 0 : hsh[i - 1].second, mul(pw[i].second, s[i] - 'a' + 1, mod2), mod2);
    }
}

pair<ll, ll> getHash(ll x, ll y)
{
    ll res1 = add(hsh[y].first, (x == 0) ? 0 : -1 * hsh[x - 1].first, mod1);
    res1 = mul(res1, (x == 0) ? 1 : inv[x].first, mod1);

    ll res2 = add(hsh[y].second, (x == 0) ? 0 : -1 * hsh[x - 1].second, mod2);
    res2 = mul(res2, (x == 0) ? 1 : inv[x].second, mod2);

    return {res1, res2};
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

}
