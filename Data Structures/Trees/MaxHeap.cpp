#include <iostream>
using namespace std;
#define MAX 12
class heap
{
    int n,a[MAX];
public:
    int insert(int,int*,int);
    int del(int*,int);
    void display(int*,int);
};
int heap::insert(int item,int a[],int n)
{
    int c=n+1;
    if(c==MAX)
    {
        cout<<"Heap is full!";
        return n;
    }
    int p=c/2;
    while(c!=1&&item>a[p])
    {
        a[c]=a[p];
        c=p;
        p=c/2;
    }
    a[c]=item;
    return n+1;
}
void heap::display(int a[],int n)
{

  for(int i=1;i<=n;i++)
  {
      cout<<a[i]<<" ";
  }
}
int heap::del(int a[],int n)
{
    int p=1,c,temp;
    c=2*p;
    temp=a[n--];
    while(c<=n)
    {
        if(c<n)
        {
            if(a[c]<a[c+1])
            {
                c++;
            }
        }
        if(temp>a[c])
            break;
        a[p]=a[c];
        p=c;
        c=2*p;
    }
    a[p]=temp;
    return n;
}
int main()
{

    heap H;
    int n;
    cout<<"Enter n:";
    cin>>n;
    int b[MAX];
    for(int i=1;i<=n;i++)
    {
        cin>>b[i];
    }
    H.display(b,n);
    cout<<"\n";
    n=H.insert(17,b,n);
    H.display(b,n);
    n=H.del(b,n);
    cout<<"\n";
    H.display(b,n);
}
