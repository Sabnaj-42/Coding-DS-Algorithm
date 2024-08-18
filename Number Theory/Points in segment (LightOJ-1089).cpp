#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll mp[200005];
ll a[2][100005];
int main()
{
    map<ll,ll>::iterator it;//iterator while er moddhe declare korle kaj kortechilo..kano kortechilona ami janina
    int c=1;
    int t;cin>>t;
    while(t--)
    {
       ll n,q;cin>>n>>q;
       map<ll,ll>m;
       vector<ll>v;
       for(int i=0;i<n;i++)
       {
           cin>>a[0][i]>>a[1][i];
           v.push_back(a[0][i]);
           v.push_back(a[1][i]);

       }
       sort(v.begin(),v.end());
       ll val=2;
       for(int i=0;i<v.size();i++)
       {
           if(!m[v[i]])
           {
               m[v[i]]=val;
               val+=2;
           }
       }
       for(int i=0;i<n;i++)
       {
           mp[m[a[0][i]]]+=1;
           mp[m[a[1][i]]+1]-=1;

       }
       for(int i=1;i<=val;i++)
       {
           mp[i]+=mp[i-1];
       }
       printf("Case %d:\n",c++);
       while(q--)
       {
           ll p;cin>>p;
            it=m.lower_bound(p);
           //cout<<(*it).second<<endl;
           if((*it).first==p)
            cout<<mp[(*it).second]<<endl;
           else cout<<mp[(*it).second-1]<<endl;
       }
       memset(mp,0,sizeof(mp));
    }
}
