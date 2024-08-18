#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s,t;
    cin>>s>>t;
    int n,m;
    n=s.size();
    m=t.size();
    int a[n+1][m+1];
    for(int i=0;i<=n;i++)a[i][0]=0;
    for(int i=0;i<=m;i++)a[0][i]=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(s[i-1]==t[j-1])
            {
                a[i][j]=a[i-1][j-1]+1;
            }
            else
            {
                a[i][j]=max(a[i][j-1],a[i-1][j]);
            }
        }
    }
    string ans="";
    int x=n,y=m;
    while(x>0&&y>0)
    {
        if(a[x-1][y]==a[x][y])
            x--;
        else if(a[x][y-1]==a[x][y])y--;
        else
        {
            ans=s[x-1]+ans;
            x--;
            y--;
        }
    }
    cout<<ans<<endl;
}
