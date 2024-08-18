#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector<string>v;
ll dp[1001][1001];
const long long mod=1e9+7;
ll recursive(int i,int j,int n)
{
    if(i==n||j==n)return 0;
    if(v[i][j]=='*')return 0;
    if(i==n-1&&j==n-1)return 1;
    if(dp[i][j]!=-1)return dp[i][j];
   return dp[i][j]=(recursive(i+1,j,n)+recursive(i,j+1,n))%mod;

}

int main()
{
    ll n;cin>>n;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)dp[i][j]=-1;
    for(int i=0;i<n;i++)
    {
        string s;cin>>s;
        v.push_back(s);
    }
    ll ans=recursive(0,0,n);
    cout<<ans<<"\n";
}
