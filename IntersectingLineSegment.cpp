#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll direction(pair<ll, ll> a, pair<ll, ll> b, pair<ll, ll> c)
{
    ll value = (c.first - a.first) * (b.second - a.second) - (b.first - a.first) * (c.second - a.second);
    return value;
}
bool onpoint(pair<ll, ll> a, pair<ll, ll> b, pair<ll, ll> c)
{
    if(min(a.first, b.first) <= c.first && max(a.first, b.first) >= c.first && min(a.second, b.second) <= c.second && max(a.second, b.second) >= c.second)
    {
        return true;
    }
    else return false;
}

bool intersect(pair<ll, ll> a, pair<ll, ll> b, pair<ll, ll> c, pair<ll, ll> d)
{
    ll d1 = direction(c, d, a);
    ll d2 = direction(c, d, b);
    ll d3 = direction(a, b, c);
    ll d4 = direction(a, b, d);

    if(((d1 > 0 && d2 < 0) || (d1 < 0 && d2 > 0)) && ((d3 > 0 && d4 < 0) || (d3 < 0 && d4 > 0))) return true;
    else if(d1 == 0 && onpoint(c, d, a)) return true;
    else if(d2 == 0 && onpoint(c, d, b)) return true;
    else if(d3 == 0 && onpoint(a, b, c)) return true;
    else if(d4 == 0 && onpoint(a, b, d)) return true;
    else return false;
}
int main()
{
    pair<ll, ll> a = {0, 0}, b = {5, 0}, c = {3, 2}, d = {3, -2};
    pair<ll, ll> aa = {3, 10}, bb = {3, 2}, cc = {0, 0}, dd = {5, 0};

    if(intersect(a, b, c, d)) cout << "True" << endl;
    else cout << "False" << endl;

    if(intersect(aa, bb, cc, dd)) cout << "True" << endl;
    else cout << "False" << endl;
}
