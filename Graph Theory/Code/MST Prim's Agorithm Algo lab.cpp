#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int>>graph[100];
bool visit[100];
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int a,b,c;cin>>a>>b>>c;
        graph[a].push_back({b,c});
        graph[b].push_back({a,c});
    }
    for(int i=0;i<n;i++)visit[i]=0;
    visit[0]=1;
    int cnt=0;
    int cost=0;
    while(cnt<n-1)
    {
        int mn=INT_MAX;
        int r,c;
        for(int i=0;i<n;i++)
        {
            if(visit[i]==1)
            {
                for(int j=0;j<graph[i].size();j++)
                {
                    if(mn>graph[i][j].second)
                    {
                        if(visit[graph[i][j].first]==0)
                        {r=i;c=j;mn=graph[i][j].second;}
                    }
                }
            }

        }
        cost+=mn;
            cout<<r<<" "<<graph[r][c].first<<endl;
            visit[graph[r][c].first]=1;
            cnt++;
    }
    cout<<cost<<endl;
}
