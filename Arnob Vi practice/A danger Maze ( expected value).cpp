#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;cin>>t;
    for(int k=1;k<=t;k++)
    {
        int n;cin>>n;
        long long sum=0,f=0,num=n;
        for(int i=0;i<n;i++)
        {
            long long d;cin>>d;
            if(d>0)f=1;
            else num--;
            sum+=abs(d);
        }
        printf("Case %d: ",k);
        if(f==0)
            cout<<"inf"<<endl;
        else
        {
            long long e=__gcd(sum,num);
            cout<<sum/e<<'/'<<num/e<<endl;
        }
    }
}
