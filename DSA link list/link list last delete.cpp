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
void last_delete()
{
  node *prev;
  temp=head;
  while(temp->link!=NULL)
  {
      prev=temp;
      temp=temp->link;
  }
  prev->link=NULL;

}
int main()
{
    int n;cin>>n;
    for(int i=1;i<=n;i++)
    {
        int data;cin>>data;
        creation(data);
    }
    temp=head;
    while(temp!=NULL)
    {
        cout<<temp->info<<" ";
        temp=temp->link;
    }
    cout<<endl;
    last_delete();
    temp=head;
    while(temp!=NULL)
    {
        cout<<temp->info<<" ";
        temp=temp->link;
    }

}
