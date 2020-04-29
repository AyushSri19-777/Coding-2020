#include <iostream>
using namespace std;
class HeapS
{
public:
    void sort(int *,int);
    void adjust(int *,int,int);
};
void HeapS::sort(int a[],int n)
{
   int i,j,temp;
   for(i=n-1;i>0;i--)
   {
       temp=a[1];
       a[1]=a[i+1];
       a[i+1]=temp;
       adjust(a,1,i);
   }
}
void HeapS::adjust(int a[],int p,int n)
{
    int c,temp;
    temp=a[p];
    c=2*p;
    while(c<=n)
    {
        if(c<n&&a[c+1]>a[c])
            c++;
        if(temp>a[c])
            break;
        else
        {
            a[c/2]=a[c];
            c=c*2;
        }
    }
        a[c/2]=temp;
        return;
}
int main()
{
    int n,i;
    HeapS h;
    cout<<"Enter the number of elements";
    cin>>n;
    int a[n];
    a[0]=n;
    cout<<"Enter array elements";
    for(i=1;i<=n;i++)
        cin>>a[i];
    cout<<"Unsorted Array: \n";
    for(i=1;i<=n;i++)
        cout<<a[i]<<" ";
    h.sort(a,n);
    cout<<"\nSorted Array: \n";
    for(i=1;i<=n;i++)
        cout<<a[i]<<" ";
}
