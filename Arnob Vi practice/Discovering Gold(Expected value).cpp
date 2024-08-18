#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;cin>>t;
    for(int c=1;c<=t;c++)
    {
        int n;cin>>n;
        long double pro[n+1],g[n+1],exp=0;

        for(int i=1;i<=n;i++)
        {
           cin>>g[i];pro[i]=0;

        }

        pro[1]=1;
        exp=g[1];
        for(int i=2;i<=n;i++)
        {
            for(int j=1;j<=6&&i-j>=1;j++)
            {
                int k=min(6,(n-(i-j)));
                pro[i]=pro[i]+((1/(long double)k)*pro[i-j]);
            }
            exp+=pro[i]*g[i];
        }
        printf("Case %d: ",c);
        cout<<fixed<<setprecision(9)<<exp<<endl;
    }
}
