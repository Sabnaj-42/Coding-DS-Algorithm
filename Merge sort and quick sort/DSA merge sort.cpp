#include<bits/stdc++.h>
using namespace std;
int b[100];
void mergee(int *a,int lb,int mid,int up)
{
   int  i=lb;
   int  j=mid+1;int k=lb;
    while(i<=mid&&j<=up)
    {
        if(a[i]<=a[j])
        {
            b[k]=a[i];i++;
        }
        else
        {
            b[k]=a[j];
            j++;
        }
        k++;
    }
    if(i>mid)
    {
        while(j<=up)
        {
            b[k]=a[j];j++;k++;
        }
    }
    else
    {
        while(i<=mid)
        {
            b[k]=a[i];i++;k++;
        }
    }
    for(k=lb;k<=up;k++)
    {
        a[k]=b[k];
    }
}
void mergesort(int *a,int lb,int ub)
{
    if(lb<ub)
    {
        int mid=(lb+ub)/2;
        mergesort(a,lb,mid);
        mergesort(a,mid+1,ub);
        mergee(a,lb,mid,ub);
    }
}
int main()
{
    int n;cin>>n;int a[n];
    for(int i=0;i<n;i++)cin>>a[i];
    mergesort(a,0,n-1);
    for(int i=0;i<n;i++)cout<<a[i]<<" ";
    cout<<endl;
}
