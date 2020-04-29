#include <iostream>
#include <stdio.h>
#define max 10
using namespace std;
class Qsort
{
public:
     void quick(int*,int,int);
};
void Qsort::quick(int a[],int low,int high)
{
    int i=low,j=high+1,temp,pivot;
    if(low<high)
          pivot=a[low];
    do{
        do{
            i++;
        }while(a[i]<pivot);
        do{
            j--;
        }while(a[j]>pivot);
        if(i<j)
        {
            temp=a[i];
            a[i]=a[j];
            a[j]=temp;
        }
    }while(i<j);
    temp=a[low];
    a[low]=a[j];
    a[j]=temp;
    quick(a,low,j-1);
    quick(a,j+1,high);
}
int main()
{
    int n,i;
    Qsort q;
    cout<<"Enter the number of elements";
    cin>>n;
    int a[n];
    cout<<"Enter array elements";
    for(i=0;i<n;i++)
        cin>>a[i];
    cout<<"Unsorted Array: \n";
    for(i=0;i<n;i++)
        cout<<a[i]<<" ";
    q.quick(a,0,n-1);
    cout<<"Sorted Array: \n";
    for(i=0;i<n;i++)
        cout<<a[i]<<" ";

}
