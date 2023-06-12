
#include<bits/stdc++.h>
#define ll long long
using namespace std;

InsersionSort(int a[], int n)
{
     a[0] = -1e9;
     for(int i = 2; i <= n; i++)
     {
         int temp = a[i], j = i - 1;
         while(temp < a[j])
         {
             a[j + 1] = a[j];
             j = j - 1;
         }
         a[j + 1] = temp;
     }
}
int main()
{
    int n;
    cin >> n;
    int a[n + 1];
    for(int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        a[i] = x;
    }
    InsersionSort(a, n);
    for(int i = 1; i <= n; i++)
    {
        cout << a[i] << " ";
    }
}
