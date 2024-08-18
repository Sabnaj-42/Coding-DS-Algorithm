#include<bits/stdc++.h>
using namespace std;
int stak[100];
int t=-1;
void push(int a)
{
    t++;
    stak[t]=a;
}
void pop()
{
    t--;
}
int top()
{
    return stak[t];
}
void postevaluation(string s)
{
    int v=0;int cnt=0;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]>='0'&&s[i]<='9')
        {
          int b=s[i]-'0';
          v=(v*10)+b;cnt++;
        }
        else if(s[i]==',')
        {
          if(cnt>0)
            {push(v);
            v=0;cnt=0;}
        }
        else
        {
            int a=top();
            pop();
            int b=top();
            pop();
            int c;
            if(s[i]=='*') c=b*a;
            else if(s[i]=='/')c=b/a;
            else if(s[i]=='+')c=b+a;
            else if(s[i]=='-')c=b-a;
            push(c);

        }
    }
    int ans=top();
    cout<<ans<<endl;
}
int main()
{
  string s;cin>>s;
  postevaluation(s);
}
