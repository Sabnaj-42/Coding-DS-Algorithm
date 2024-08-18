#include<bits/stdc++.h>
using namespace std;
int main()
{
    while(1)
    {
        string s;
        cin>>s;
        if(s=="*")break;
        int n=s.size();
        vector<int>z(n,0);
        int left=0,right=0;
        for(int k=1; k<n; k++)//string z array calculation
        {
            if(k>right)
            {
                left=right=k;
                while(right<n&&s[right]==s[right-left])
                {
                    right++;
                }
                z[k]=right-left;
                right--;
            }
            else
            {
                int k1=k-left;
                if(z[k1]<right-k+1)
                {
                    z[k]=z[k1];
                }
                else
                {
                    left=k;
                    while(right<n&&s[right]==s[right-left])
                        right++;
                    z[k]=right-left;
                    right--;
                }
            }

        }
        for(int i=0;i<n;i++)cout<<z[i]<<" ";
        //cout<<endl;
       /* vector<int>mod;
        for(int i=1;i<n;i++)
        {
            if(n%i==0)mod.push_back(i);
        }
        int g=0;
        for(int i=0;i<mod.size();i++)
        {
           int d=mod[i],f=0;
           while(d<n)
           {
               if(z[d]<mod[i]){f=1;break;}
               d+=mod[i];
           }
           if(f==0){cout<<n/mod[i]<<endl;g=1;break;}

        }
        if(g==0)cout<<1<<endl;*/

    }
}
