#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;cin>>t;
    int m[1003];
    for(int i=1;i<=1000;i++)m[i]=10000;
    m[1]=0;
    for(int i=1;i<=1000;i++)
    {
        int temp=i;
        int j=1;
        while(j<=i)
        {
            int d=temp/j;
            if(d+i<=1000)
               m[d+i]=min(m[d+i],m[i]+1);
            j++;
        }
    }
    //for(int i=1;i<=20;i++)cout<<m[i]<<" ";
    //cout<<endl;
    while(t--)
    {
        int n,k;cin>>n>>k;
        int a[n+1],b[n+1];
        for(int i=1;i<=n;i++)cin>>a[i];
        for(int i=1;i<=n;i++)cin>>b[i];
        vector<pair<int,int>>p;
        long long res=0;
        for(int i=1;i<=n;i++)
        {
            int c=m[a[i]];
            if(c==0)res+=b[i];
            else
               p.push_back({c,b[i]});
        }
        sort(p.begin(),p.end());
         n=p.size();
         k=min(k,n*12);
        int ans[n+1][k+1];
        for(int i=0;i<n;i++)
            ans[i][0]=0;
        for(int j=1;j<=k;j++)
        {
            int c=p[0].first;
            int d=p[0].second;
            if(j>=c)
                ans[0][j]=d;
            else ans[0][j]=0;
        }
        for(int i=1;i<n;i++)
        {
            for(int j=1;j<=k;j++)
            {
                if(p[i].first>j)ans[i][j]=ans[i-1][j];
                else
                {
                    ans[i][j]=max(ans[i-1][j],ans[i-1][j-p[i].first]+p[i].second);
                }
            }
        }
        cout<<res+ans[n-1][k]<<endl;

    }
}
