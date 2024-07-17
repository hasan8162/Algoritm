#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll d1[100], d2[100], board[100][100], row[100], col[100];

bool attacking(ll n, ll r, ll c)
{
    if(d1[r - c + n] || d2[r + c] || row[r] || col[c]) return true;
    else return false;
}

ll nqueen(ll n, ll r)
{
    ll s = 0;

    if(r == n)
        return 1;

    for(int i = 0; i < n && !s; i++)
    {
        if(!attacking(n, r, i))
        {

            board[r][i] = 1;
            d1[r - i + n] = 1;
            d2[r + i] = 1;
            row[r] = 1;
            col[i] = 1;

            s = nqueen(n, r + 1);

            if(!s)
            {
                board[r][i] = 0;
                d1[r - i + n] = 0;
                d2[r + i] = 0;
                row[r] = 0;
                col[i] = 0;
            }
        }
    }

    return s;
}

int main()
{
    ll n;
    cin >> n;

    ll s = nqueen(n, 0);

    if(!s)
    {
        cout << "NO" << endl;
        return 0;
    }

    cout << "YES" << endl;

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}
