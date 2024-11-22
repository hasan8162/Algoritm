#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll eular_phi(ll n)
{
    vector<ll> primes;
    ll x = n;
    for(int i = 2; i * i <= x; i++)
    {
        if(x % i == 0)
        {
            primes.push_back(i);
            while(x % i == 0) x /= i;
        }
    }

    if(x > 1) primes.push_back(x);


    for(auto x : primes)
    {
        n = n - n / x;
    }
    return n;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

