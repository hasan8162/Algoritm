#include<bits/stdc++.h>
#define ll long long
using namespace std;

struct activity{

    ll start, finish;
    string activity_number;
};

bool compare(activity a, activity b)
{
   if(a.finish != b.finish)
   {
       return a.finish < b.finish;
   }
   else{
      return a.start <= b.start;
   }
}

vector<string> activity_selection(activity a[], ll n)
{
    vector<string> A;
    A.push_back(a[0].activity_number);
    ll i = 0;

    for(int m = 1; m < n; m++)
    {
        if(a[m].start >= a[i].finish)
        {
            A.push_back(a[m].activity_number);
            i = m;
        }
    }

    return A;
}

int main()
{
    activity a[] = {{1, 4, "a1"}, {3, 5, "a2"}, {0, 6, "a3"}, {5, 7, "a4"}, {3, 8, "a5"}, {5, 9, "a6"}, {6, 10, "a7"}, {8, 11, "a8"}, {8, 12, "a9"}, {2, 13, "a10"}, {12, 14, "a11"}};
    ll n = sizeof(a) / sizeof(a[0]);

    sort(a, a + n, compare);

    vector <string> selected_activity;
    selected_activity = activity_selection(a, n);

    for(int i = 0; i < selected_activity.size(); i++)
    {
        cout << selected_activity[i] << " ";
    }
}
