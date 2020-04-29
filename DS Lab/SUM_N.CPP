#include <iostream.h>
#include <conio.h>
int main()
{
   int n,sum=0,i;
   cout<<"Enter the value of n";
   cin>>n;
   for(i=1;i<=n;i++)
   sum+=n;
   cout<<"The sum is "<<sum;
   getch();
   return 0;

}