#include <iostream.h>
#include <conio.h>
int main()
{
   int i,n,pos,val;
   cout<<"Enter the size of array";
   cin>>n;
   int a[100];
   cout<<"Enter the array elements";
   for(i=0;i<n;i++)
   cin>>a[i];
   cout<<"Enter the element and the position you want to insert it";
   cin>>val>>pos;
   for(i=n;i>pos;i--)
   {
     a[i+1]=a[i];
   }
   a[i]=val;
   cout<<"The modified array is : \n";
   for(i=0;i<n+1;i++)
   cout<<a[i]<<"  ";
   getch();
   return 0;
}