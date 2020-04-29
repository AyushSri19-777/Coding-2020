#include <iostream>
#include <stdio.h>
using namespace std;
class time
{
    int hour;
    int min;
    int sec;
public:
    void read();
    void add(time,time);
    void subtract(time,time);
    void display();
    time()
    {
        hour=0;
        min=0;
        sec=0;
    }
};
void time::read()
{
    cin>>hour>>min>>sec;
}
void time::display()
{
    cout<<hour<<":"<<min<<":"<<sec;
}
void time::add(time t1,time t2)
{
    time t3;
    if((t1.sec+t2.sec)>60)
    {
       t3.min++;
       t3.sec+=(t1.sec+t2.sec)-60 ;
    }

    else
        t3.sec+=t1.sec+t2.sec;
    if((t1.min+t2.min)>60)
    {
        t3.hour++;
        t3.min+=(t1.min+t2.min)-60;
    }

    else
        t3.min+=t1.min+t2.min;
    t3.hour+=t1.hour+t2.hour;
    t3.display();
}
void time::subtract(time t1,time t2)
{
    time t3;
    if(t1.sec<t2.sec)
    {
       t1.sec+=60;
       t1.min--;
       t3.sec=t1.sec-t2.sec;
    }
    else
        t3.sec=t1.sec-t2.sec;
    if(t1.min<t2.min)
    {
       t1.min+=60;
       t1.hour--;
       t3.min=t1.min-t2.min;
    }
    else
        t3.min=t1.min-t2.min;
    t3.hour=t1.hour-t2.hour;
    t3.display();
}
int main()
{
    time t1,t2,t;
    int ch;
    cout<<"Enter the 1st time in hours minutes seconds ";
    t1.read();
    cout<<"Enter the 2nd time in hours minutes seconds ";
    t2.read();
    cout<<"\nTime no. 1 :";
    t1.display();
    cout<<"\nTime no. 2 :";
    t2.display();
    cout<<"\nEnter choice\n1.Add times \n2.Subtract times ";
    cin>>ch;
    switch(ch)
    {
        case 1:cout<<"\nAdded time :";
               t.add(t1,t2);
               break;
        case 2:cout<<"\nDifference in time :";
               t.subtract(t1,t2);
               break;
        default:"Wrong Choice!!";
    }
    return 0;
}
