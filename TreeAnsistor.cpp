#include <bits/stdc++.h>
#define ll long long
using namespace std;

vector<vector<ll> > adj;
vector<vector<ll> > ansistor;
vector<ll> depth;


ll getAnsistor(ll n, ll k)
{
    for(int i = 14; i >= 0; i--)
    {
        if(k & (1 << i))
        {
            n = ansistor[n][i];
        }
    }

    return n;
}

ll LCA(ll x, ll y)
{
    if(depth[x] < depth[y])
    {
        y = getAnsistor(y, depth[y] - depth[x]);
    }
    else if(depth[x] > depth[y])
    {
        x = getAnsistor(x, depth[x] - depth[y]);
    }

    if(x == y)
    {
        return x;
    }
    for(int i = 14; i >= 0; i--)
    {
        if(ansistor[x][i] != ansistor[y][i]){
            x = ansistor[x][i];
            y = ansistor[y][i];
        }
    }

    return ansistor[x][0];


}

void dfs(ll n, ll p)
{
    for(int i = 0; i < 15; i++)
    {
        ansistor[n][i] = -1;
    }

    ansistor[n][0] = p;
    for(int i = 1; i < 15; i++)
    {
        ll v = ansistor[n][i - 1];
        if(v == -1) break;
        ansistor[n][i] = ansistor[v][i - 1];
    }

    for(auto x : adj[n])
    {
        dfs(x, n);
    }
}

void bfs(ll n)
{
    queue<ll> q;
    q.push(n);
    depth[n] = 1;

    while(q.size())
    {
        ll v = q.front();
        q.pop();

        for(auto x : adj[v])
        {
            if(!depth[x])
            {
                depth[x] = depth[v] + 1;
                q.push(x);
            }
        }
    }
}

int main()
{
    ll n;
    cin >> n;

    adj = vector<vector<ll> > (n);
    ansistor = vector<vector<ll> > (n, vector<ll> (16));
    depth = vector<ll> (n);

    for(int i = 0; i < n; i++)
    {
        ll m;
        cin >> m;

        for(int j = 0; j < m; j++)
        {
            ll x;
            cin >> x;

            adj[i].push_back(x);
        }

        dfs(0, -1);
    }

    bfs(0);

    ll q;
    cin >> q;

    while(q--)
    {
        ll x, y;
        cin >> x >> y;

        cout << LCA(x, y) << endl;
    }

}
