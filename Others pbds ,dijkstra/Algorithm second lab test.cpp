#include<bits/stdc++.h>
using namespace std;
int main()
{
   int n,nn;
   float m,mx;cin>>n>>nn>>m>>mx;
   float w=m;
   float a1[n],b1[nn],a2[n],b2[nn];
   for( int i=0;i<n;i++)
    cin>>a1[i];
    for(int  i=0;i<nn;i++)cin>>b1[i];
     for( int i=0;i<n;i++)
    cin>>a2[i];
    for(int  i=0;i<nn;i++)cin>>b2[i];
   vector<pair<float,float>>v1,v2;
   for( int i=0;i<n;i++)
   {
      float d=b1[i]/a1[i];
      v1.push_back({d,a1[i]});
   }
    for( int i=0;i<nn;i++)
   {
      float d=b2[i]/a2[i];
      v2.push_back({d,a2[i]});
   }
   sort(v1.begin(),v1.end());
    reverse(v1.begin(),v1.end());
     sort(v2.begin(),v2.end());
    reverse(v2.begin(),v2.end());
   int sum=0;
   float fract=0;
   float nonfact=0;
   int j=0;
   for(int i=0;i<n&&j<nn;i++)
   {
      float d1=v1[i].first;
      float d2=v2[i].first;
      if(d1>=d2)
      {
          if(v1[i].second<=m)
          {sum+=v1[i].second*d1;
             m-=v1[i].second;}
      }
      else
      {
         float d1=min(v2[j].second,(min((5-fract),m)));
         sum+=d1*v2[j].first;
         m-=d1;
         fract+=d1;j++;
      }
      if(m<=0)break;

   }
   printf("%d (fractional - %f kgs,non-fractional- %f kgs",sum,fract,w-fract);

}
/*
8 15  5
2 3 4 5 3 1 2 3
10 20 50 60 30 6 14 20
*/
