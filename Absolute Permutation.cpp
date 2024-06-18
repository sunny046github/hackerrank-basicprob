
#include <iostream>
#include <stdio.h>
#include <string>
#include <algorithm>
#include <stdlib.h>
#include <memory.h>
using namespace std;
const int maxn=1000010;
int test,n,k,a[maxn];
bool kt[maxn];



int main()
{
    cin>>test;
    for (int t=1;t<=test;++t)
    {
        memset(kt,false,sizeof(kt));
        cin>>n>>k;
        if (k==0) for (int i=1;i<=n;++i) cout<<i<<" ";
        else
        if (n%(2*k)!=0) cout<<-1;
        else
        {
            for (int i=1;i<=n;++i) a[i]=i;
            for (int i=1;i<=n;++i)
                if (!kt[i])
                {
                    swap(a[i],a[i+k]);
                    kt[i]=true;
                    kt[i+k]=true;
                }
            for (int i=1;i<=n;++i) cout<<a[i]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}
