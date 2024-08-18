#include<bits/stdc++.h>
using namespace std;
class node
{
public:
    int info;
    node *link;
};
node *temp,*head=NULL;

void creation(int data) //linked list creation
{
    node *ptr;
    ptr=new node();
    ptr->info=data;
    ptr->link=NULL;
    if(head==NULL)
    {
        head=ptr;
        temp=ptr;
    }
    else
    {
        temp->link=ptr;
        temp=ptr;
    }
}
void first_insertion(int data)
{
    node *ptr=new node();
    ptr->info=data;
    temp=head;
    head=ptr;
    ptr->link=temp;

}
int main()
{

    int n;
    cout<<"Enter the number of element  : "<<endl;cin>>n;
    for(int i=1; i<=n; i++)
    {
        int d;
        cin>>d;
        creation(d);
    }
    temp=head;
    while(temp!=NULL)
    {
        cout<<temp->info<<" ";
        temp=temp->link;
    }
    cout<<endl;
    cout<<"Enter the element you want to insert "<<endl;
    cin>>n;
    first_insertion(n);
    temp=head;
    while(temp!=NULL)
    {
        cout<<temp->info<<" ";
        temp=temp->link;
    }
}
