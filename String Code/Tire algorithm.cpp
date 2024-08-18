#include<bits/stdc++.h>
using namespace std;
const int sizee=26;
struct node
{
    bool endOfWord;
    node *ar[sizee];
};
node *getNode()//to create a new node;
{
    node *n=new node;
    n->endOfWord=false;
    for(int i=0; i<sizee; i++)
        n->ar[i]=NULL;
    return n;
}
void insertt(node *root,string st)
{
    node *tempRoot=root;//we won't change root
    for(int i=0; i<st.size(); i++)
    {
        int index=st[i]-'a';
        if(tempRoot->ar[index]==NULL)
        {
            tempRoot->ar[index]=getNode();
        }
        tempRoot=tempRoot->ar[index];
    }
    tempRoot->endOfWord=true;
}
bool searchh(node *root,string st)
{
    node *tempRoot=root;
    for(int i=0; i<st.size(); i++)
    {
        int index=st[i]-'a';
        if(tempRoot->ar[index]==NULL)
        {

            return false;
        }
        tempRoot=tempRoot->ar[index];
    }
    return tempRoot->endOfWord;
}

int main()
{
    node *root=getNode();
    while(1)
    {
        int code;
        cin>>code;
        if(code==1)
        {
            cout<<"Enter String to insert :";
            string st;
            cin>>st;
            insertt(root,st);
        }
        else if(code==2)
        {
            cout<<"Enter string to search ";
            string st;
            cin>>st;
            cout<<searchh(root,st)<<endl;
        }
        else break;
    }

}
