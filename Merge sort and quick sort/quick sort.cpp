#include<bits/stdc++.h>
using namespace std;
int partition(int *a,int lb,int ub)
{
    int pivot=a[lb];
    int start=lb;
    int end=ub;
    while(start<end)
    {
        while(a[start]<=pivot)
        {
            start++;
        }
        while(a[end]>pivot)

        {
            end--;
        }
        if(start<end)
        {
            swap(a[start],a[end]);
        }
    }
    swap(a[lb],a[end]);
    return end;
}
void quicksort(int *a,int lb,int ub)
{
    if(lb<ub)
    {
        int loc=partition(a,lb,ub);
        quicksort(a,lb,loc-1);
        quicksort(a,loc+1,ub);
    }
}
int main()
{
  int n;cin>>n;
  int a[n];
  for(int i=0;i<n;i++)cin>>a[i];
  quicksort(a,0,n-1);
  for(int i=0;i<n;i++)cout<<a[i]<<" ";
  cout<<endl;

}
