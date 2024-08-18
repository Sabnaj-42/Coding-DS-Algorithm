#include<bits/stdc++.h>
using namespace std;
vector<long long>p;
 int maxx=100005;
 const int maxn=1151;
long long c[maxn];
 long long mx=100000007;
#define uniq(vec) vec.resize(distance(vec.begin(),unique(vec.begin(),vec.end())))//unique number and resize vector
void perfect()
{
    for(long long i=2;i<mx;i++)
    {
        long long k=i*i;
            while(k<=(long long)1e10)
            {
                p.push_back(k);
                k*=i;
            }

    }
    sort(p.begin(),p.end());
    uniq(p);
   // long long n=p.size();//cout<<n<<endl;
}

void catalan()
{
    c[0]=1;
    c[1]=1;
   for(int i=2;i<maxn;i++)
   {
       for(int j=0;j<i;j++)
       {
           c[i]+=(c[j]*c[i-j-1])%mx;
           c[i]=c[i]%mx;
       }
   }
}
int main()
{
    perfect();
    catalan();


    int t;cin>>t;
    int casee=1;
    while(t--)
    {
       long long a,b;cin>>a>>b;
      int n=upper_bound(p.begin(),p.end(),b)-p.begin()-(lower_bound(p.begin(),p.end(),a)-p.begin());
       printf("Case %d: ",casee);casee++;//cout<<n<<endl;
       if(n==0)cout<<0<<endl;
       else
       cout<<c[n]<<endl;

    }

}
