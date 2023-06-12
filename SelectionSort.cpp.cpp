
#include<bits/stdc++.h>
#define ll long long
using namespace std;

MIN(int a[], int n, int k)
{
    int mini = a[k], loc = k;
    for(int i = k + 1; i <= n; i++)
    {
        if(a[i] < mini)
        {
            loc = i;
            mini = a[i];
        }
    }
    return loc;
}
SelectionSort(int a[], int n)
{
     for(int i = 1; i <= n; i++)
     {
         int loc = MIN(a, n, i);
         int temp = a[i];
         a[i] = a[loc];
         a[loc] = temp;
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
    SelectionSort(a, n);
    for(int i = 1; i <= n; i++)
    {
        cout << a[i] << " ";
    }
}
