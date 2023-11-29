
#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    ll inf = 1e9, n = 5;
    ll adj_mat[n][n] = {{0, 3, 8, inf, -4},
                        {inf, 0, inf, 1, 7},
                        {inf, 4, 0, inf, inf},
                        {2, inf, -5, 0, inf},
                        {inf, inf, inf, 6, 0}};

    cout << "D[" << 0 << "]" << endl;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(adj_mat[i][j] < inf)
             cout << adj_mat[i][j] << " ";
            else cout << "inf" << " ";
        }
        cout << endl;
    }

    cout << endl;

    for(int k = 0; k < n; k++)
    {
        cout << "D[" << k + 1 << "]" << endl;
        ll d[n][n];

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(adj_mat[i][k] < inf && adj_mat[k][j] < inf)
                {
                    d[i][j] = min(adj_mat[i][k] + adj_mat[k][j], adj_mat[i][j]);
                }
                else d[i][j] = adj_mat[i][j];
            }
        }

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(d[i][j] < inf)
                    cout << d[i][j] << " ";
                else cout << "inf" << " ";
                adj_mat[i][j] = d[i][j];
            }
            cout << endl;
        }

        cout << endl;
    }
}
