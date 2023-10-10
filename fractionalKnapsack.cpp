#include<bits/stdc++.h>
#define ll long long
using namespace std;

bool compare(pair <ll, ll> a, pair <ll, ll> b)
{
    double value1 = a.first / (a.second * 1.0);
    double value2 = b.first / (b.second * 1.0);

    return value1 > value2;
}
double knapsack(vector<pair<ll, ll> > pr, ll len, ll sack_capacity)
{
    sort(pr.begin(), pr.end(), compare);
    ll baki = sack_capacity;
    ll i = 0;
    double ans = 0.0;

    for(i = 0; i < len; i++)
    {
        if(pr[i].second > baki)
        {
            ans += pr[i].first * (baki / (pr[i].second * 1.0));
            break;
        }
        else
        {
            ans += pr[i].first;
            baki -= pr[i].second;
        }
    }

    return ans;
}

int main()
{
    ll profit[] = {60, 100, 120};
    ll weight[] = {10, 20, 30};
    ll sack_capacity = 50;

    vector<pair<ll, ll> > arr;

    ll len = sizeof(profit) / sizeof(profit[0]);

    for(int i = 0; i < len; i++)
    {
        arr.push_back({profit[i], weight[i]});
    }

    cout << fixed << setprecision(10) << knapsack(arr, len, sack_capacity) << endl;
}
