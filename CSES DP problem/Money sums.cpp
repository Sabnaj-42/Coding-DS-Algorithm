#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll dp[100][100005];

int main()
{
   ll n;cin>>n;
   ll a[n];
   for(int i=0;i<n;i++)cin>>a[i];
   dp[0][0]=1;
   for(int i=1;i<100005;i++)
   {
      if(i==a[0])dp[0][i]=1;
      else dp[0][i]=0;
   }
   for(int i=1;i<n;i++)
   {
       for(int j=0;j<100005;j++)
       {
         if(j==0){dp[i][j]=1;continue;}
         if(j<a[i]){dp[i][j]=dp[i-1][j];continue;}
         dp[i][j]=max(dp[i-1][j],dp[i-1][j-a[i]]);
       }
   }
   vector<int>ans;
   for(int i=1;i<100005;i++)
   {
       if(dp[n-1][i]==1)ans.push_back(i);
   }
   cout<<ans.size()<<"\n";
   for(int i=0;i<ans.size();i++)cout<<ans[i]<<" ";
   cout<<"\n";
}

