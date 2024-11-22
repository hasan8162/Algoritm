#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll phi[2000001], primes[2000001], dp[2000001];

void seive()
{
    for(int i = 1; i <= 2000000; i++) phi[i] = i;

    for(int i = 2; i <= 2000000; i++)
    {
        if(primes[i]) continue;
        phi[i] = i - 1;

        for(int j = i + i; j <= 2000000; j += i)
        {
            phi[j] = phi[j] - phi[j] / i;
            primes[j] = 1;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

