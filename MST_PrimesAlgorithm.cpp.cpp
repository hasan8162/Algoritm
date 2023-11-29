#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    //It will only print the total cost of the minimum spanning tree, also you can modify this to get the the also
    //This code is for undirected graph only, you can try the sample input below

    ll vertex, edges;

    cin >> vertex >> edges;

    vector<pair<ll, ll> > adj[vertex + 1];

    for(int i = 0; i < edges; i++)
    {
        ll x, y, w;
        cin >> x >> y >> w;
        adj[x].push_back({y, w});
        adj[y].push_back({x, w});
    }

    priority_queue<pair<ll, ll>, vector<pair<ll, ll> >, greater<pair<ll, ll>> > pr;
    pr.push({0, 1});
    ll visited[vertex + 1] = {}, min_cost = 0;

    while(pr.size())
    {
       ll node = pr.top().second, weight = pr.top().first;
       pr.pop();

       if(visited[node] == 0)
       {
           min_cost += weight;
           visited[node] = 1;

           for(auto x : adj[node])
           {
               if(visited[x.first] == 0)
               {
                   pr.push({x.second, x.first});
               }
           }
       }
    }

    cout << min_cost << endl;
}

/*
Sample Input
6 9
1 2 6
1 2 3
2 3 2
2 4 5
3 4 3
3 5 4
4 5 2
4 6 3
5 6 5
//Sample Output
13
*/
