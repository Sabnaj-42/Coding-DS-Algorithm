
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
const long long mx=500005;
vector<ll>v[mx];
int main()
{
   for(ll i=1;i<mx;i++)
   {
       for(ll j=i;j<mx;j+=i)v[j].push_back(i);
   }

}
