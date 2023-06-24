#include<bits/stdc++.h>
using namespace std;

vector<int>a[20];
int v, visited[20];

void add(int x, int y)
{
    a[x].push_back(y);
    a[y].push_back(x);
}

void dfs(int source)
{
    visited[source] = 1;
    cout << source << "->";
    for(int i = 0; i < a[source].size(); i++)
    {
        if(visited[a[source][i]] == 0)
        {
            dfs(a[source][i]);
        }
    }
}
int main()
{
   v = 6;
   add(1, 5);
   add(1, 4);
   add(2, 3);
   add(2, 5);
   add(2, 6);
   add(3, 4);
   add(3, 6);
   add(5, 4);
   add(6, 4);
   add(6, 5);
   dfs(1);
}
