//one way

#include<iostream>
using namespace std;

class node
{
public:
    int info;
    node *link;
    node *prev,*next,*mid;
};

node *head=NULL;

creation(int data)
{
    node *ptr,*temp;
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

traverse()
{
    node *srt;
    for(srt=head; ;)
    {
        if(srt->link!=NULL)
        {
            cout<<srt->info<<" ";
            srt=srt->link;
        }
        else {cout<<srt->info<<endl;break;}
    }
}

//insertion.........
f_insertion()
{
    int item;
    cin>>item;

    node *ptr;
    ptr=new node();
    ptr->info=item;
    ptr->link=head;
    head=ptr;
}

l_insertion()
{
    int item;
    cin>>item;

    node *ptr,*srt;
    ptr=new node();

    ptr->info=item;
    ptr->link=NULL;

    for(srt=head; ;)
    {
        if(srt->link==NULL)
        {
            srt->link=ptr;
            break;
        }
        else srt=srt->link;
    }
}

b_insertion(int s_item)
{
    cin>>s_item;

    node *srt,*temp;
    for(srt=head; ;)
    {
        if(srt->info==s_item)
        {
            if(srt==head)
            {
                f_insertion();
                break;
            }
            else
            {
                node *ptr;
                ptr=new node();

                int item;
                cin>>item;

                ptr->info=item;
                ptr->link=srt;
                temp->link=ptr;
                break;
            }
        }
        else
        {
            //if(srt==NULL){cout<<"NOT FOUND!"<<endl;break;}
            temp=srt;
            srt=srt->link;
        }
        if(srt==NULL){cout<<"NOT FOUND!"<<endl;break;}
    }
}

a_insertion(int s_item)
{
    cin>>s_item;

    node *srt;
    for(srt=head; ;)
    {
        if(srt->info==s_item)
        {
            if(srt->link==NULL)
            {
                l_insertion();
                break;
            }
            else
            {
                int item;
                cin>>item;

                node *ptr;
                ptr=new node();

                ptr->info=item;
                ptr->link=srt->link;
                srt->link=ptr;
                break;
            }
        }
        else
        {
            srt=srt->link;
        }
        if(srt==NULL){cout<<"NOT FOUND!"<<endl;break;}

    }
}

f_deletion()
{
    head=head->link;
}

l_deletion()
{
    node *srt,*temp;
    for(srt=head; ;)
    {
        if(srt->link==NULL)
        {
            temp->link=NULL;
            break;
        }
        else
        {
            temp=srt;
            srt=srt->link;
        }
    }
}

g_deletion(int s_item)
{
    cin>>s_item;
    node *srt,*temp;
    for(srt=head; ;)
    {
        if(srt->info==s_item)
        {
            if(srt==head){f_deletion();break;}
            else if(srt->link==NULL){l_deletion();break;}
            else {temp->link=srt->link;break;}
        }
        else {temp=srt;srt=srt->link;}
    }
}

b_deletion(int s_item)
{
    cin>>s_item;

    node *srt,*temp,*prev=NULL;
    for(srt=head; ;)
    {
        if(srt->info==s_item)
        {
            if(temp==head){f_deletion();break;}
            else
            {
                prev->link=srt;
                break;
               // prev=srt;
            }
        }
        else
        {
            prev=temp;
            temp=srt;
            srt=srt->link;
        }
    }
}

a_deletion(int s_item)
{
    cin>>s_item;

    node *srt,*temp;
    for(srt=head; ;)
    {
        if(srt->info==s_item)
        {
            temp=srt->link;
            if(srt->link==NULL){cout<<"NOT POSSIBLE!"<<endl;break;}
            else if(temp->link==NULL){l_deletion();break;}
            else
            {
                srt->link=temp->link;
                break;
            }
        }
        else
        {
            if(srt->link==NULL){cout<<"NOT FOUND!"<<endl;break;}
            srt=srt->link;
        }
    }

}

l_search(int s_item)
{
    int i=1;
    cin>>s_item;
    node *srt;

    for(srt=head; ;)
    {
        if(srt->info==s_item)
        {
            cout<<"FOUND!"<<endl;
            cout<<"THE POSSITION IS : "<<i<<endl;
            break;
        }
        else
        {
            if(srt->link==NULL)cout<<"NOT FOUND!"<<endl;
            else srt=srt->link;i++;
        }
    }
}

node *mid(node *b,node *e)
{
    node *f,*s,*srt;
    f=b;
    s=f->link;
    while(s!=e)
    {
        s=s->link;
        if(s!=e)
        {
            f=f->link;
            s=s->link;
        }
    }return f;
}

b_search(int s_item)
{
    cin>>s_item;

    node *b,*e,*m;
    b=head;
    e=NULL;
    while(e!=b)
    {
        m=mid(b,e);
        if(m->link==NULL){cout<<"NOT FOUND!"<<endl;break;}
        else if(m->info==s_item){cout<<"FOUND!"<<endl; break;}
        else if(m->info<s_item){b=m->link;}
        else {e=m;}
       // if(m->link==NULL){cout<<"NOT FOUND!"<<endl;break;}
    }
}

int main()
{
    int n,item;
    cin>>n;

    for(int i=0;i<n;i++)
    {
        cin>>item;
        creation(item);
    }traverse();
    while(1)
    {
        int c;
        cin>>c;

        if(c==1)
        {
            f_insertion();
            traverse();
        }
        else if(c==2)
        {
            l_insertion();
            traverse();
        }
        else if(c==3)
        {
            int s_item;
            b_insertion(s_item);
            traverse();
        }
        else if(c==4)
        {
            int s_item;
            a_insertion(s_item);
            traverse();
        }
        else if(c==5)
        {
            f_deletion();
            traverse();
        }
        else if(c==6)
        {
            l_deletion();
            traverse();
        }
        else if(c==7)
        {
            int s_item;
            g_deletion(s_item);
            traverse();
        }
        else if(c==8)
        {
            int s_item;
            b_deletion(s_item);
            traverse();
        }
        else if(c==9)
        {
            int s_item;
            a_deletion(s_item);
            traverse();
        }
        else if(c==10)
        {
            int s_item;
            l_search(s_item);
        }
        else if(c==11)
        {
            int s_item;
            b_search(s_item);
        }
        else{cout<<"EXIT!";return 0;}
    }
}
