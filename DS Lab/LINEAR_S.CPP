#include <iostream>
#include <conio.h>
using namespace std;
int main()
{
  int a[100],n,i,val,f=0;
  cout<<"Enter the size of array ";
  cin>>n;
  cout<<"Enter the array elements ";
  for(i=0;i<n;i++)
  cin>>a[i];
  cout<<"Enter the element to be searched";
  cin>>val;
  for(i=0;i<n;i++)
  {
    if(a[i]==val)
    {
	f=1; break;

    }
  }
  if(f==1)
  cout<<"Element found at position "<<i+1;
  else
  cout<<"Search element not found";
  getch();
  return 0;
}

