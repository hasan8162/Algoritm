#include<bits/stdc++.h>
using namespace std;


int split(int a[], int start, int End)
{
    int pivot = a[start], i = End + 1;

    for(int j = End; j >= start; j--)
    {
        if(a[j] > pivot)
        {
            i--;
            swap(a[i], a[j]);
        }
    }
    swap(a[i - 1], a[start]);
    return (i - 1);
}
void quickSort(int a[], int start, int End)
{
    if(start < End)
    {
        int index = split(a, start, End);
        quickSort(a, start, index - 1);
        quickSort(a, index + 1, End);
    }
}
int main()
{
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    quickSort(a, 0, n - 1);

    for(int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
}
