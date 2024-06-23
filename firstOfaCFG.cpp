#include<bits/stdc++.h>
#define ll long long
using namespace std;

map<char, vector<string> > production;
ll num;

set<char> first(char x)
{
    set<char> result;


    for(auto c : production[x])
    {
        for(int i = 0; i < c.size();)
        {
            if(!isupper(c[i]))
            {
                result.insert(c[i]);
                break;
            }
            else
            {
                set<char> st = first(c[i]);
                ll eps = 0;

                for(auto f : st)
                {
                    if(f != '&') result.insert(f);
                    else if(f == '&' && i + 1 == c.size()) result.insert(f);
                    else
                    {
                        eps = 1;
                    }
                }

                if(eps) i++;
                else break;
            }
        }
    }
    return result;
}
int main()
{
    cout << "Enter number of Production: ";
    cin >> num;

    for(int i = 0; i < num; i++)
    {
        string s;
        cin >> s;

        string left;

        for(int j = 2; j < s.size(); j++)
        {
            left += s[j];
        }

        production[s[0]].push_back(left);
    }

    set<char> ans;
    char non_terminal;
    cout << "Find first of: ";
    cin >> non_terminal;

    ans = first(non_terminal);
    cout << "{ ";
    for(auto x : ans) cout << x << " ";
    cout << "}";

}
/*

Input
8
E=TB
B=+TB
B=&
T=FC
C=*FC
C=&
F=i
F=(E)

Result
FIRST(E) = { i ( };
FIRST(B) = { + & };
FIRST(T) = { i ( };
FIRST(C) = { * & };
FIRST(F) = { i ( };

*/
