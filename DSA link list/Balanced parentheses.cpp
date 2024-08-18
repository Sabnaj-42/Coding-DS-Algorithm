
#include<bits/stdc++.h>
using namespace std;
char Stack[1000];
int top=-1;
void push(char x)
{
    if(top==999)
        cout<<"overflow"<<endl;
    else
    {
        top++;
        Stack[top]=x;
    }
}
void pop()
{
    if(top==-1)
        cout<<"Underflow"<<endl;
    else
        top--;
}
char Top()
{
    if(top==-1)
        cout<<"Underflow"<<endl;
    else
       return Stack[top];
}
bool check_bp(string s)
{
    for(int i=0;i<s.size();i++)
    {
        bool ans=true;
        if(s[i]=='(' ||s[i]=='[' ||s[i]=='{'  )
            push(s[i]);
        else if(s[i]==')')
        {
            if(top!=-1 && Stack[top]=='(')
                top--;
                else
                {
                    ans=false;
                    return ans;
                }
        }
        else if(s[i]=='}')
        {
            if(top!=-1 && Stack[top]=='{')
                top--;
                else
                {
                    ans=false;
                    return ans;
                }
        }
        else if(s[i]==']')
        {
            if(top!=-1 && Stack[top]=='[')
                top--;
                else
                {
                    ans=false;
                    return ans;
                }
        }

    }
    if(top!=-1)
        return false;
    else
        return true;

}
int main()
{
    //push('(');
    string s;
    cout<<"enter string : ";
    getline(cin,s);
    if(check_bp(s)==true)
        cout<<"Balanced"<<endl;
    else
        cout<<"Not balanced"<<endl;
}
