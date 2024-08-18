#include<bits/stdc++.h>
using namespace std;
long long ans[105][100005];
int main()
{
   long long n,ww;cin>>n>>ww;
   long long w[n+1],p[n+1];
   for(int i=1;i<=n;i++)
   {
       cin>>w[i]>>p[i];
   }
   for(int i=0;i<=n;i++)
   {
       for(int j=1;j<=100003;j++)
       {
           ans[i][j]=INT_MAX;
       }
   }
   for(int i=1;i<=n;i++)
   {
       for(int j=1;j<=100000;j++)
       {
           if(j<p[i])ans[i][j]=ans[i-1][j];
           else
            ans[i][j]=min(ans[i-1][j],ans[i-1][j-p[i]]+w[i]);
       }
   }
   for(int i=100000;i>=0;i--)
   {
       if(ans[n][i]<=ww){cout<<i<<endl;break;}
   }
}
