#include<bits/stdc++.h>
using namespace std;
int main()
{
    int tt;cin>>tt;
    for(int k=1;k<=tt;k++)
    {
        int t,d;cin>>t>>d;
        printf("Case %d: ",k);
        if(t==0)cout<<1<<endl;
        else if(t%2==1)cout<<0<<endl;
        else
        {
             long double ans=1;

             while(t>0)
             {
                 ans*=((t-1)/(double)(t+1));
                 t-=2;
             }
             cout<<fixed<<setprecision(9)<<ans<<endl;
        }
    }
}
