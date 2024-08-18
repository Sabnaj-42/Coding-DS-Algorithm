#include"testlib.h"
#include<iostream>
using namespace std;
int main(int argc, char* argv[])
{
    registerGen(argc, argv, 1);
    int n=atoi(argv[1]);
    int q=atoi(argv[2]);
    int nn=rnd.next(1,n);
    int qq=rnd.next(0,q);
    cout<<nn<<" "<<qq<<endl;
    for(int i=0;i<nn;i++)
    {
        for(int j=0;j<nn;j++)
        {
            cout<<rnd.next(0,1000);
            if(j<nn-1)cout<<" ";
        }
        cout<<endl;
    }
    for(int i=0;i<qq;i++)
    {
        int x1=rnd.next(1,nn);
        int y1=rnd.next(1,nn);
        int x2=rnd.next(x1,nn);
        int y2=rnd.next(y1,nn);
        cout<<x1<<" "<<y1<<" "<<x2<<" "<<y2<<endl;
    }

}

