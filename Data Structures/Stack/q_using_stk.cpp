#include <iostream>
#include <stdio.h>
#define maxe 10
using namespace std;
class qusingst
{
    int s1[maxe],s2[maxe],top;
public:
    void addq();
    int delq();
    void display();
    qusingst()
    {
        top=-1;
    }
};
void qusingst::addq()
{
    int x;
    cout<<"Enter the element";
    cin>>x;
    if(top==maxe-1)
        cout<<"Overflow!";
    else
        s1[++top]=x;
}
int qusingst::delq()
{

}
