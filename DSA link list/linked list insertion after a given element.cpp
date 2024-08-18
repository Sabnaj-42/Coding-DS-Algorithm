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
void after_insertion(int element,int data)
{
    node *ptr=new node();
    node *prev;
    ptr->info=data;
    ptr->link=NULL;
    temp=head;
        while(temp!=NULL)
        {
            if(temp->info==element)break;
            temp=temp->link;
        }
        if(temp==NULL)
            cout<<"Insertion not possible"<<endl;
        else
        {
            if(temp->link==NULL)
            {
               temp->link=ptr;
            }
            else
            {
                node *after=temp->link;
               temp->link=ptr;
               ptr->link=after;
            }

        }
}
int main()
{
    int n;
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        int data;
        cin>>data;
        creation(data);
    }
    cout<<"enter the element after that you want to insert last and enter the data ";
    int c,d;
    cin>>c>>d;
    after_insertion(c,d);
    temp=head;
    while(temp!=NULL)
    {
        cout<<temp->info<<" ";
        temp=temp->link;
    }
    cout<<endl;
}
