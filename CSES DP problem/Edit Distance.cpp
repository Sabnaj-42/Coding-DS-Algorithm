#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll dp[5002][5002];
ll solve(int i,int j,string &s1,string &s2)
{
   if(i==s1.size()||j==s2.size())
     return max(s1.size()-i,s2.size()-j);
    if(dp[i][j]!=-1)return dp[i][j];
  if(s1[i]==s2[j])
  {
     return dp[i][j]=solve(i+1,j+1,s1,s2);
  }
  ll op1=1+solve(i,j+1,s1,s2);//add
  ll op2=1+solve(i+1,j,s1,s2);//remove
  ll op3=1+solve(i+1,j+1,s1,s2);//replace
  return dp[i][j]=min(op1,min(op2,op3));

}
int main()
{
    string s1,s2;cin>>s1>>s2;
    for(int i=0;i<=5000;i++)
       for(int j=0;j<=5000;j++)dp[i][j]=-1;
    ll ans=solve(0,0,s1,s2);
    cout<<ans<<"\n";
}
