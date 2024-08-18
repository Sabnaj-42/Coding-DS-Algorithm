#include<bits/stdc++.h>
using namespace std;
#define ll long long
struct node
{
    ll l,r,i;
};
bool comp(node a,node b)
{
    if(a.l!=b.l)return a.l<b.l;
    else return a.r<b.r;
}
node q[200005];
ll a[200005],ans[200005];
ll cnt=0;
vector<ll>fr(200005,0);
void add(int pos)
{
    fr[a[pos]]++;
    if(fr[a[pos]]==1)cnt++;
}
void rmove(int pos)
{
   fr[a[pos]]--;
   if(fr[a[pos]]==0) cnt--;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
   int n,qq;cin>>n>>qq;
   int ct=1;
   map<ll,ll>m;
   for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(m[a[i]]==0)
        {
            m[a[i]]=ct;
            a[i]=ct;ct++;
        }
        else
        {
            a[i]=m[a[i]];
        }
    }
   for(int i=0;i<qq;i++)
   {
       cin>>q[i].l>>q[i].r;
       q[i].i=i;

   }
   sort(q,q+qq,comp);
   int ml=1,mr=0;
   for(int i=0;i<qq;i++)
   {
       ll b=q[i].l,e=q[i].r;
       ll in=q[i].i;
       while(ml>b)
       {
         ml--;add(ml);
       }
       while(mr<e)
       {
          mr++;
          add(mr);
       }
       while(ml<b)
       {
          rmove(ml);ml++;
       }
       while(mr>e)
       {
           rmove(mr);mr--;
       }
       ans[in]=cnt;
   }
   for(int i=0;i<qq;i++)
   {
      cout<<ans[i]<<"\n";
   }
}
