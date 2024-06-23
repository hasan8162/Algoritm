#include<bits/stdc++.h>
#define ll long long
using namespace std;

//We are considering & as epsolone

map<char, vector<string> > production;
vector<char> prod;
ll num;
char starting;

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

set<char> follow(char x)
{
    set<char> result;

    if(x == starting) result.insert('$');

    for(auto c : prod)
    {
        for(auto f : production[c])
        {
            ll found = 0;
            for(int i = 0; i < f.size(); i++)
            {
                if(found == 1)
                {
                    if(!isupper(f[i]))
                    {
                        //cout << c << " " << f[i] << endl;
                        result.insert(f[i]);
                        break;
                    }
                    else if(isupper(f[i]))
                    {
                        set<char> st = first(f[i]);
                        ll esp = 0;

                        for(auto fol : st)
                        {
                            if(fol != '&')
                                result.insert(fol);
                            else esp = 1;
                        }

                        if(!esp) break;
                        else if(i + 1 == f.size())
                        {
                            if(x != c)
                            {
                                st = follow(c);
                                for(auto fol : st) result.insert(fol);
                                break;
                            }
                        }
                    }
                }

                if(f[i] == x)
                {
                    found = 1;
                    //cout << c << endl;
                    if(i + 1 == f.size())
                    {
                        if(x != c)
                        {
                            set<char> st = follow(c);
                            for(auto fol : st) result.insert(fol);
                            break;
                        }
                    }
                }
            }
        }
    }
    return result;
}

int main()
{
    cout << "Enter number of Production: ";
    cin >> num;
    cout << "Enter starting terminal: ";
    cin >> starting;

    set<char> term;
    ll sz = 0;

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
        term.insert(s[0]);

        if(term.size() != sz)
        {
            prod.push_back(s[0]);
        }
        sz = term.size();
    }

    set<char> ans;
    char non_terminal;

    while(1)
    {
        cout << "Find Follow of: ";
        cin >> non_terminal;
        ans = follow(non_terminal);
        cout << "{ ";
        for(auto x : ans) cout << x << ", ";
        cout << "}" << endl;
    }

}
/*
Input
8
E
E=TB
B=+TB
B=&
T=FC
C=*FC
C=&
F=i
F=(E)

Result
FOLLOW(E) = {$ )};
FOLLOW(B) = {$ )};
FOLLOW(T) = {+ $ )};
FOLLOW(C) = { + $ ) };
FOLLOW(F) = {* + $ )};
*/

