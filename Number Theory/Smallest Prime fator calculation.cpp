#include<bits/stdc++.h>
using namespace std;
#define N 10000001
long long l=10000000000;
vector<long long>spf(N+1,1);
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
   // vector<long long>prime;
//Smallest Prime factor calculation of every Number from 2 to N
    for(long long i=2; i<=N; i++)
    {
        if(spf[i]==1)
        {
            spf[i]=i;
            for(long long j=i*i;j<N;j+=i)
            {
                if(spf[j]==1)spf[j]=i;
            }
        }
    }
    long long t;
    cin>>t;
    while(t--)
    {

        long long x,y,pp;
        cin>>x>>y;
        long long d=abs(x-y);
        long long mx,mn;
        mx=max(x,y);
        mn=min(x,y);
        if(d==1)cout<<-1<<endl;
        else  if(x==1&&y==1)cout<<1<<endl;
        else
        {
            pp=d;
            long long res=l;
            mx=max(x,y);
            mn=min(x,y);
            if(__gcd(mx,mn)!=1)cout<<0<<endl;
            else
            {
                vector<long long>ans;

                while(d>1)
                {
                    long long fact=spf[d];
                    ans.push_back(fact);
                    while(d%fact==0)d/=fact;

                }

            for(int i=0;i<ans.size();i++)
            {
                res=min(res,ans[i]-(mx%ans[i]));
            }
             cout<<res<<endl;
            }
        }

    }
}
