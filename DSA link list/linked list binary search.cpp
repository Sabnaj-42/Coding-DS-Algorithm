#include<bits/stdc++.h>
using namespace std;
class node
{
public:
    int info;
    node *link;
};
node *head=NULL,*temp;
void creation(int data)
{
    node *ptr=new node();
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
node *middle(node *start,node* last)
{
    node *fast,*slow;
    slow=start;
    fast=start->link;
    while(fast!=last)
    {
        fast=fast->link;
        if(fast!=last)
        {
            slow=slow->link;
            fast=fast->link;
        }

    }
    return slow;
}
node *binry_search(int data)
{
    int flag=0;
    node *f=head;
    node *l=NULL;
    node *mid;
    do
    {
        mid=middle(f,l);
        if(mid->info==data)
        {
            cout<<"search item is found at address :"<<mid<<endl;
            flag=1;
            break;
        }
        else if(mid->info>data)l=mid;
        else f=mid->link;

        }while(f!=l);
    if(flag==0)cout<<"data not found"<<endl;

}
int main()
{
    int n;
    cin>>n;
    for(int i=0; i<n; i++)
    {
        int c;
        cin>>c;
        creation(c);
    }
            cout<<"Enter search iteam ";
        int d;
        cin>>d;
        binry_search(d);
}
