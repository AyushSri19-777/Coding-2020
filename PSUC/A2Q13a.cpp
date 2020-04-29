#include<iostream>
using namespace std;
int *qsort(int arr[],int size, int flag)
{
    int *p=arr;
    if(flag==1)
    {
        for(int i=0; i<size-1; i++)
        {
            for(int j=0; j<size-i-1; j++)
            {
                if(*(p+j)>*(p+j+1))
                {
                    int temp=*(p+j);
                    *(p+j)=*(p+j+1);
                    *(p+j+1)=temp;
                }
            }
        }
    }
    else if(flag==2)
    {
        for(int i=0; i<size-1; i++)
        {
            for(int j=0; j<size-i-1; j++)
            {
                if(*(p+j)<*(p+j+1))
                {
                    int temp=*(p+j);
                   *(p+j)=*(p+j+1);
                    *(p+j+1)=temp;
                }
            }
        }
    }
    return p;

}
int main()
{
    int arr[100], flag=1, size;
    cout<<"Enter size of the array: ";
    cin>>size;
    cout<<"Enter elements of the array: "<<endl;
    for(int i=0; i<size; i++)
    {
        cout<<"Enter a["<<i<<"]: ";
        cin>>arr[i];
    }
    cout<<"Flag=1 for Ascending and Flag=2 for Descending"<<endl;
    cout<<"Flag=";
    cin>>flag;
    qsort(arr, size, flag);
    cout<<"The array in required sort is: ";
    for(int i=0; i<size; i++)
    {
    cout<<arr[i]<<"\t";
    }
}
