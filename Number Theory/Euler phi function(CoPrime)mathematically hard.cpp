#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
ll mx=5000000,i,j;
ll ph[5000001];
void phi(int m)
{
    for(i=1;i<=m;i++)ph[i]=i;
    for(i=2;i<=m;i++)
    {
        if(ph[i]==i)
        {
            for(j=i;j<=m;j=i+j)
            {
                ph[j]/=i;
                ph[j]*=(i-1);
            }
        }
    }
    for(i=1;i<=m;i++)ph[i]=ph[i-1]+ph[i]*ph[i];
}
int main()
{
    phi(mx);
    int t,k;cin>>t;
    for(k=1;k<=t;k++)
    {
       ll a,b;cin>>a>>b;
        cout<<"Case "<<k<<": "<<ph[b]-ph[a-1]<<endl;
    }
}
