#include <iostream>
#include <conio.h>
using namespace std;
int main()
{
   int a[100],n,i,j,temp;
   cout<<"Enter the size of the array\n";
   cin>>n;
   cout<<"Enter the array elements\n";
   for(i=0;i<n;i++)
   cin>>a[i];
   cout<<"The unsorted array\n";
   for(i=0;i<n;i++)
   cout<<a[i]<<" ";
   for(i=0;i<n;i++)
   {
     for(j=0;j<n-1;j++)
     {
	if(a[j]>a[j+1])
	{
	  temp=a[j];
	  a[j]=a[j+1];
	  a[j+1]=temp;
	}
     }
   }
   cout<<"Sorted array\n ";
   for(i=0;i<n;i++)
   cout<<a[i]<<" ";
   getch();
   return 0;
}
