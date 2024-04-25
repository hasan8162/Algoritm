#include<bits/stdc++.h>
#define ll long long
using namespace std;



class DSU{

    vector<ll> rnk, parent;

    public:

    DSU(ll n)
    {
        rnk.resize(n + 1, 1);
        parent.resize(n + 1, 0);

        for(int i = 0; i <= n; i++)
        {
            parent[i] = i;
        }
    }

    ll Find(ll node)
    {
        if(node == parent[node])
            return node;
        return parent[node] = Find(parent[node]);
    }

    void Union(ll u, ll v) {

        ll par_u = Find(u), par_v = Find(v);

        if(rnk[par_u] <= rnk[par_v])
        {
            rnk[par_u] += rnk[par_v];
            parent[par_v] = par_u;
        }

        else
        {
            rnk[par_v] += rnk[par_u];
            parent[par_u] = par_v;
        }
    }
};
int main()
{

}
