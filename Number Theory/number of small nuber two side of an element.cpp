#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;cin>>t;
    for(int k=1;k<=t;k++)
    {
        long long n;long long ans=0;cin>>n;
    long long a[n+2],l1[n+1],l2[n+1];
    for(int i=1;i<=n;i++)cin>>a[i];
    a[0]=INT_MIN;
    a[n+1]=INT_MIN;
    stack<int>s;
    s.push(0);
    for(int i=1;i<=n;i++)
    {
        while(1)
        {
            int j=s.top();
            if(a[i]<=a[j])s.pop();
            else
            {
                s.push(i);
                l1[i]=i-j;
                break;

            }
        }
    }
    stack<int>s2;
    s2.push(n+1);
    for(int i=n;i>0;i--)
    {
        while(1)
        {
            int j=s2.top();
            if(a[i]<a[j])s2.pop();
            else
            {
                s2.push(i);
                l2[i]=j-i;
                break;

            }
        }
    }

    for(int i=1;i<=n;i++)
    {
        ans=max(ans,a[i]*((l1[i]+l2[i])-1));
    }
    printf("Case %d: ",k);
    cout<<ans<<endl;

    }

}

