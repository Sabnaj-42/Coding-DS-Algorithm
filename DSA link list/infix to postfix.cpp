
#include<bits/stdc++.h>
using namespace std;
char stackk[10000];
int topp=-1;
char push(char a)
{
    topp++;
    stackk[topp]=a;
}
char top()
{
    return stackk[topp];

}
int pop()
{
    topp--;
}
bool isoperand(char c)
{
    if((c>='A'&&c<='Z')||(c>='a'&&c<='z'))
    {
        return true;
    }
    return  false;
}

bool isoperator(char c)
{
    if(c=='+'||c=='-'||c=='*'||c=='/'||c=='^') return true;
    return false;
}


int precedence(char c )
{
    if(c=='+'||c=='-') return 1;
    if(c=='*'||c=='/') return 2;
    if(c=='^') return 3;
}



int main()
{
    string exp;
    getline(cin,exp);
    push('(');
    string s="";
    for(int i=0; i<exp.length(); i++)
    {
        if(exp[i]==','||exp[i]==' ') continue;
        else  if(isoperand(exp[i]))
        {

            s+=exp[i];
        }
        else if(exp[i]=='(') push(exp[i]);
        else  if(exp[i]==')')
        {
            while(top()!='(')
            {
                s+=stackk[topp];
                topp--;
            }
            topp--;
        }
        else   if(isoperator(exp[i]))

        {
            int j= precedence(exp[i]);

            if(top()=='(') push(exp[i]);
            else   if(j>precedence(top()))
            {
                push(exp[i]);

            }
            else if(j<=precedence(top()))
            {
                while(top()!='('&&j<=precedence(top()))
                {

                    s+=stackk[topp];
                    topp--;
                }


                push(exp[i]);


            }



        }




    }


    while(topp!=0)
    {
        s+=top();
        topp--;
    }


    cout<<s<<endl;


}
