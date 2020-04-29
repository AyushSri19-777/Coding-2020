#include <iostream>
#include <conio.h>
using namespace std;
int main()
{
   int a[100],n,i,j,min,pos,temp;
   cout<<"\nEnter the size of the array\n";
   cin>>n;
   cout<<"Enter the array elements\n";
   for(i=0;i<n;i++)
   cin>>a[i];
   cout<<"The Unsorted Array\n";
   for(i=0;i<n;i++)
   cout<<a[i]<<" ";
   min=a[0];
   for(i=0;i<n-1;i++)
   {
     min=a[i];
     pos=i;
     for(j=i+1;j<n;j++)
     {
       if(min>a[j])
       {
       min=a[j];
       pos=j;
       }
     }
     temp=a[pos];
     a[pos]=a[i];
     a[i]=temp;
   }
   cout<<"Sorted array\n";
   for(i=0;i<n;i++)
   cout<<a[i]<<" ";
   getch();
   return 0;
}



