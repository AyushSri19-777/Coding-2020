#include<iostream>
using namespace std;
int main()
{
    int n,a[100],i,lar=0;
    cout<<"Enter size";
    cin>>n;
    cout<<"Enter elements";
    for(i=0;i<n;i++)
        cin>>a[i];
    int *ptr=a;
    for(i=0;i<n;i++)
    {
        if(*(ptr+i)>lar)
            lar=*(ptr+i);
    }
    cout<<"The largest element: "<<lar;
    return 0;
}
