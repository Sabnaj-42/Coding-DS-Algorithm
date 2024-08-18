#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll dp[2][100005];
int main()
{
   ll n,x;cin>>n>>x;
   ll a[n],b[n];
   for(int i=0;i<n;i++)cin>>a[i];
   for(int i=0;i<n;i++)cin>>b[i];
   for(int i=0;i<n;i++)
   {
       for(ll j=1;j<=x;j++)
       {
           if(a[i]<=j)dp[i%2][j]=max(dp[1-(i%2)][j],dp[1-(i%2)][j-a[i]]+b[i]);
           else dp[i%2][j]=dp[1-(i%2)][j];
       }
   }
   cout<<dp[(n-1)%2][x]<<"\n";
}
