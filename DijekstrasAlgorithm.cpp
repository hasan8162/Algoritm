#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    // this for directed graph and sample is given below, taking 0 as the source node
    ll n, edges;
    cin >> n >> edges;

    vector<pair<ll, ll> > adj_lst[n];

    for(int i = 0; i < edges; i++)
    {
        ll x, y, w;
        cin >> x >> y >> w;

        adj_lst[x].push_back({y, w});
    }

    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>> > pq;
    pq.push({0, 0});
    ll path_weight[n] = {}, visited[n] = {};

    for(int i = 1; i < n; i++) path_weight[i] = 1e9;

    while(pq.size())
    {
        ll node = pq.top().second;
        pq.pop();

        if(visited[node] == 0)
        {
            for(auto x : adj_lst[node])
            {
                ll nod = x.first, weight = x.second;
                if(path_weight[nod] > path_weight[node] + weight) //relaxation
                {
                    path_weight[nod] = path_weight[node] + weight;
                    pq.push({path_weight[nod], nod});
                }
            }
        }
    }

    for(int i = 0; i < n; i++) cout << i << " " << path_weight[i] << endl;
}
/*
sample input
5 10
0 1 10
0 4 5
1 2 1
1 4 2
2 3 4
3 2 6
3 0 7
4 2 9
4 1 3
4 3 2
Sample output
0 0
1 8
2 9
3 7
4 5
*/
