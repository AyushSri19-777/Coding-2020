#include <iostream.h>
#include <conio.h>
int main()
{
  int n,f=1;
  cout<<"Enter the number whose factorial you want to calculate ";
  cin>>n;
  while(n!=0)
  {
     f*=n;
     n--;
  }
  cout<<"\nThe factorial is "<<f;
  getch();
  return 0;
}