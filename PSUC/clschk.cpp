#include<iostream>
using namespace std;
const int size=10;
class array{
   int a[size];
   public:
       int setval();
       int display();
       int sortt();
};
int array::setval()
{
    cout<<"Enter the values\n";
    for(int i=0;i<size;i++)
        cin>>a[i];
        return 0;
}
int array::display()
{
     for(int i=0;i<size;i++)
      cout<<a[i]<<"\t";
      return 0;
}
int array::sortt()
{
    int t=0,j,i;
    for(i=0;i<size-1;i++)
    {
        for(j=0;j<size-i-1;j++)
            {
                if(a[j]>a[j+1])
                {
                    t=a[j];
                    a[j]=a[j+1];
                    a[j+1]=t;
                }
            }
    }
    return 0;
}
int main()
{
    array a1;
    a1.setval();
    cout<<"Array before sort\n";
    a1.display();
    a1.sortt();
    cout<<"\nArray after sort\n";
    a1.display();
    return 0;
}
