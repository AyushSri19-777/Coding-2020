#include <iostream>
using namespace std;
int main()
{
    int x=10,y=10;
    int *p1=&x,*p2=&y;
    cout<<"A :"<<(*p1)++<<"\n";
    cout<<"B :"<<*p1+(*p2)--;
    return 0;
}
