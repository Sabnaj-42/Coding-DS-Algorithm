#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;cin>>t;
    for(int k=1;k<=t;k++)
    {
        int n;cin>>n;
        printf("Case %d: ",k);
        int temp=n;
        if(n==1)printf("1\n");
        else
        {
            int ans=n+1;
            int l=2,u=n+1;
           while(l<=u)
           {
               int mid=(u+l)/2;
               long double p=1;
               int temp=n;
               long double d=n;
               for(int i=1;i<mid;i++)
               {
                   temp--;
                   p*=(temp/d);
               }
              long double pro=(long double)1-p;
             // cout<<mid<<" "<<p<<" "<<pro<<endl;
               if(pro>=0.5)
               {
                   ans=mid;
                   u=mid-1;
               }
               else l=mid+1;
           }
           printf("%d\n",ans-1);
        }
    }
}
