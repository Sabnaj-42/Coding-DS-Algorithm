#include<bits/stdc++.h>
using namespace std;
#define INT_MAX 99999
int n=4;
//cost of edge
int dist[10][10]={
    { 0,20,42,25},
    { 20,0,30,34},
    { 42,30,0,10},
    { 25,34,10,0}
};
int dp[16][4];//2^4=16//2^n
int visit_all=(1<<n)-1;
int tsp(int mask,int pos)//Here position is the staring position of sellsman
{
    if(mask==visit_all)
    {
        return dist[pos][0];
    }
    if(dp[mask][pos]!=-1)
    {
        return dp[mask][pos];
    }
    int ans=INT_MAX;
    for(int city=0;city<n;city++)//try to go to an unvisited city
    {
        if((mask &(1<<city))==0)
        {
            int newAns=dist[pos][city]+tsp(mask|(1<<city),city);
            ans=min(ans,newAns);
        }
    }
    return dp[mask][pos]=ans;
}
int main()
{

    for(int i=0;i<(1<<n);i++)
    {
        for(int j=0;j<n;j++)
            dp[i][j]=-1;
    }
    cout<<visit_all<<endl;
    cout<<tsp(1,2)<<endl;//travel start from node 2


}
//Travelling sellsman problem
