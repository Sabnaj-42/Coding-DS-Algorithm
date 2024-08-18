#include<bits/stdc++.h>
using namespace std;
class node
{
    public:
    int info;
    node *next;
    node *prev;
};
node *head=NULL, *tail=NULL,*temp;
void creation(int data)
{
    node *ptr=new node();
    ptr->info=data;
    ptr->next=NULL;
    ptr->prev=NULL;
    if(head==NULL)
    {
        head=ptr;
       tail=ptr;

    }
    else
    {
        ptr->prev=tail;
        tail->next=ptr;
        tail=ptr;

    }
}

int main()
{
    int n;cin>>n;
    for(int i=1;i<=n;i++)
    {
        int c;cin>>c;
        creation(c);
    }
    temp=head;
    while(temp!=NULL)//Forward travers
    {
        cout<<temp->info<<" ";
        temp=temp->next;
    }
    cout<<endl;
    temp=tail;
    while(temp!=NULL)//Reverse travers
    {
        cout<<temp->info<<" ";
        temp=temp->prev;
    }
    cout<<endl;
}
