 #include <iostream>
#include <conio.h>
using namespace std;
int main()
{
  int a[100],f=0,n,i,val,l=0,h,mid;
  cout<<"Enter the size of array\n";
  cin>>n;
  h=n-1;
  cout<<"Enter the array elements\n";
  for(i=0;i<n;i++)
  cin>>a[i];
  cout<<"Enter the element to be searched\n";
  cin>>val;
  while(l<=h)
  {
    mid=(l+h)/2;
    if(val==a[mid])
    {
      f=1;
      break;
    }
    else if(val>a[mid])
    l=mid+1;
    else
    h=mid-1;
  }
  if(f==1)
  cout<<"Search element found at position "<<mid+1;
  else
  cout<<"Search element not found !!";
  getch();
  return 0;
}

