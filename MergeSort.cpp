
#include<bits/stdc++.h>
#define ll long long
using namespace std;

int a[1000];

void Merge(int Beg, int mid, int End)
{
    int left[mid - Beg + 2], right[End - mid + 1];
    left[mid - Beg + 1] = 1e9;
    right[End - mid] = 1e9;
    for(int i = 0; i < mid - Beg + 1; i++)
    {
        left[i] = a[Beg + i];
    }
    for(int i = 0; i < End - mid; i++)
    {
        right[i] = a[mid + 1 + i];
    }
    int l = 0, r = 0, i = Beg;
    while(l < mid - Beg + 1 || r < End - mid)
    {
        if(left[l] <= right[r])
        {
            a[i] = left[l];
            l++;
        }
        else{
            a[i] = right[r];
            r++;
        }
        i++;
    }
}
void MergeSort(int Beg, int End)
{
     if(Beg >= End)
     {
         return;
     }
     int mid = (End + Beg) / 2;
     MergeSort(Beg, mid);
     MergeSort(mid + 1, End);
     Merge(Beg, mid, End);
}
int main()
{
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        a[i] = x;
    }
    MergeSort(0, n - 1);
    for(int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
}
