#include <iostream>
using namespace std;
int main()
{
    int arr[]={99,88,77,66,44,22};
    int *ptr1,*ptr2;
    ptr1=arr;
    ptr2=ptr1++;
    *ptr2=*ptr1+2;
    (*ptr1)++;
    cout<<arr[0]<<" "<<arr[5]<<" "<<arr[1]<<" "<<arr[2]<<"\n";
       return 0;
}
