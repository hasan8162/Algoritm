#include<bits/stdc++.h>
using namespace std;

int main()
{
    int a[10] = {1, 61, 126, 217, 2876, 6127, 39162, 98126, 712687, 1000000000};
    int b[10] = {100, 6127, 1, 61, 200, -10000, 1, 217, 10000, 1000000000};
    for(int i = 0; i < 10; i++)
    {
        int flag = 0, low = 0, high = 10 - 1, mid;
        while(low <= high)
        {
            mid=(low+high)>>1;
            if(a[mid]==b[i]) {flag=1; break;}
            else if(b[i]<a[mid]) high=mid-1;
            else low=mid+1;
        }
        if(flag==1) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}
