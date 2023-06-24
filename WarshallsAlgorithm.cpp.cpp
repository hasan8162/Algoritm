#include <bits/stdc++.h>
#define ll long long
using namespace std;

int a[20][20], p[20][20], n, edges;


int main()
{
    cin >> n >> edges;
    for(int i = 0; i < edges; i++)
    {
        int x, y;
        cin >> x >> y;
        a[x][y] = 1;
        p[x][y] = 1;
    }
    for(int k = 1; k <= n; k++)
    {
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++)
            {
                p[i][j] = p[i][j] | (p[i][k] & p[k][j]);
            }
    }
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            cout << p[i][j] << " ";
        }
        cout << endl;
    }
}
