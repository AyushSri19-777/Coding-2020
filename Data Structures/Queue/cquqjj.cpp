#include<iostream>
#include <stdlib.h>
using namespace std;
#define maxe 5
class cqueue
{
	int q[maxe],f,r;
public:
    cqueue()
	{

		f=r=0;
	}
	void addq();
	void delq();
	void display();
 };
 void cqueue::addq()
 {
     int x;
     cout<<"Enter the element";
     cin>>x;
	if((r+1)%maxe==0&&(f)%maxe==0)
		cout<<"\nQueue is Full";
	else
	{
		cout<<"Rerea= "<<r;
		r=(r+1)%maxe;
		q[r]=x;
		//cout<<"\nA["<<r<<"]="<<x;
	}
 }
 void cqueue::delq()
 {
	if(r==f)
		cout<<"\nQueue is Empty";
	else
	{
		f=(f+1)%maxe;
		cout<<"Deleted element: "<<q[f];
	}
 }
 void cqueue::display()
 {
      if(r==f)
	    cout<<"Queue is Empty";
      else
      {
         cout<<"Rear= "<<r;
         for(int i=(f+1)%maxe;i!=(r+1)%maxe;i=(i+1)%maxe)
            cout<<q[i]<<"\t";
      }
 }
int main ()
 {
	//clrscr();
	cqueue c;
	int ch;
    for(;;)
    {
    cout<<"\nEnter 1.Push 2.Pop 3.Display 4.Exit";
    cin>>ch;
    switch(ch)
    {
        case 1: c.addq();
                break;
        case 2: c.delq();
                break;
        case 3: c.display();
                break;
        case 4: exit(0);
                break;
    }
}
return 0;
 }
	/*do
	{
		cout<<"\n1.Insert\n2.Delete\n3.Display\n0.Exit";
		cout<<"\nenter your choice:";
		cin>>ch;
		switch(ch)
		{
			case 1: cout<<"\nenter the element to be inserted:";
				cin>>ele;
				q.insert(ele);
				break;
			case 2: q.del();
				break;
			case 3: q.disp();
				break;
			case 0: break;
			default: cout<<"\ninvalid input";
		}
	}while(ch!=0);
	//getch();*/
