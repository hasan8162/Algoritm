#include <bits/stdc++.h>
#define ll long long
using namespace std;

vector<ll> failure(100010);

ll KMP(string &s)
{
    //s = matching_string + '#' + given_string
    ll cur = 0, mxcur = 0;

    for(int i = 1; i < s.size(); i++)
    {
        while(cur != 0 && s[cur] != s[i]) cur = failure[cur - 1];
        if(s[cur] == s[i]) cur++;
        failure[i] = cur;
        mxcur = max(mxcur, cur);
    }

    return mxcur;
}

vector<ll> adj[100010];

void buildPrefixTree(ll n) // calculate number of prefix string of pattern present in the text.
{
    for(int i = 0; i < n; i++)
    {
        ll parent = failure[i];
        adj[parent].push_back(i + 1);
    }

    //call dfs(0)
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int _;
    cin >> _;

    while(_--)
    {
        string p, t;
        cin >> p >> t;

        string s = p + '#' + t;
        ll ans = KMP(s);


        if(ans >= p.size())
        {
            cout << "YES" << endl;
        }
    }
}

//single pattern multiple text
//period finding eg: abaabaabaabaab here period is length 3 or string aba
