#include<bits/stdc++.h>
using namespace std;
vector<int> createlps(string s)
{
    vector<int>lps(s.size());
    int index=0;
    for(int i=1;i<s.size();)
    {
        if(s[i]==s[index])
        {
            lps[i]=index+1;
            i++;index++;
        }
        else
        {
            if(index!=0)
            {
                index=lps[index-1];
            }
            else
            {
                lps[i]=index;
                i++;
            }
        }
    }
    return lps;
}
int main()
{
    int t;cin>>t;
    for(int k=1;k<=t;k++)
    {
        string s;cin>>s;
        int n=s.size();
        string text;
        text=s;
        reverse(s.begin(),s.end());
        s+='#';
        s+=text;
        vector<int>lps=createlps(s);
        int ans=2*n-lps[lps.size()-1];
        printf("Case %d: %d\n",k,ans);
    }
}
