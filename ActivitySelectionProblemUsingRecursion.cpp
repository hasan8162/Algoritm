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

vector<string> activity_selection(activity a[], vector<string> A, ll i, ll j)
{
    ll m = i + 1;

    while(m < j && a[m].start < a[i].finish)
    {
        m++;
    }

    if(m < j){

        A.push_back(a[m].activity_number);
        A = activity_selection(a, A, m, j);
    }

    return A;

}

int main()
{
    activity a[] = {{0, 0, "a0"}, {1, 4, "a1"}, {3, 5, "a2"}, {0, 6, "a3"}, {5, 7, "a4"}, {3, 8, "a5"}, {5, 9, "a6"}, {6, 10, "a7"}, {8, 11, "a8"}, {8, 12, "a9"}, {2, 13, "a10"}, {12, 14, "a11"}};
    ll n = sizeof(a) / sizeof(a[0]);

    sort(a, a + n, compare);

    vector <string> selected_activity;
    selected_activity = activity_selection(a, selected_activity, 0, n);

    for(int i = 0; i < selected_activity.size(); i++)
    {
        cout << selected_activity[i] << " ";
    }
}
