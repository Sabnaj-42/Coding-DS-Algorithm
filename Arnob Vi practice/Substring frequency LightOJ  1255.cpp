#include<bits/stdc++.h>
using namespace std;
vector<int>createlps(string pattern)
{
    vector<int>lps(pattern.length());
    int index=0;//index of prefix
    for(int i=1;i<pattern.size();)//index of suffix
    {
        if(pattern[index]==pattern[i])
        {
            lps[i]=index+1;
            index++;i++;
        }
        else
        {
            if(index!=0)
            {
                index=lps[index-1];
            }
            else
            {
                lps[i]=index;i++;
            }
        }
    }
    return lps;
}

void kmp(string text,string pattern)
{
    int ans=0;
    vector<int>lps=createlps(pattern);
    int i=0,j=0;//i=text index,j=pattern index;
    while(i<text.size())
    {
        if(text[i]==pattern[j])
        {
            i++;j++;
        }
        else
        {
            if(j!=0)j=lps[j-1];
            else i++;
        }
        if(j==pattern.size())
        {
          ans++;j=lps[j-1];
        }
    }
    cout<<ans<<endl;
}
int main()
{
    int t;cin>>t;
    int c=1;
    while(t--)
    {


        string text,pattern;
    cin>>text>>pattern;
    printf("Case %d: ",c);
    kmp(text,pattern);
    c++;
    }
}
