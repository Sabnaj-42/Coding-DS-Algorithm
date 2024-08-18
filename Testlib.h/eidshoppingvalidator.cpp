#include<bits/stdc++.h>
using namespace std;
#include"testlib.h"
int main(int argc, char* argv[])
{
    registerValidation(argc, argv);
    int n=inf.readInt(1,1000,"n");
    inf.readSpace();
    int q=inf.readInt(0,500000,"q");
    inf.readEoln();
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            inf.readInt(0,1000,"p");
            if(j<n-1)
            inf.readSpace();

        }
        inf.readEoln();
    }
    for(int i=0;i<q;i++)
    {
        setTestCase(i+1);
       int x1=inf.readInt(1,n,"x1");
         inf.readSpace();
         int y1=inf.readInt(1,n,"x1");
         inf.readSpace();
         inf.readInt(x1,n,"x1");
         inf.readSpace();
         inf.readInt(y1,n,"x1");
         inf.readEoln();
    }
    inf.readEof();

}
