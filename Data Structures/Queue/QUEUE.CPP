#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#define max 20
using namespace std;
class queue
{
   int f,r;
   int q[max];
   public:
      void addq();
      void delq();
      void display();
      queue()
      {
	f=r=-1;
      }
   };
   void queue::addq()
   {
     int ele;
     cout<<"Enter the element";
     cin>>ele;
     if(r==max-1)
      cout<<"Overflow! ";
      else
      q[++r]=ele;
     }
  void queue::delq()
  {
     if(r==f)
	cout<<"Underflow! ";
     else
       cout<<q[++f];
  }
  void queue::display()
  {
     for(int i=f+1;i<=r;i++)
     cout<<q[i]<<" ";
  }
  int main()
  {
     queue q;
     int ch;
     for(;;)
     {
       cout<<"Enter \n1.Enqueue \n2.Dequque \n3.Display \n4.Exit";
       cin>>ch;
       switch(ch)
       {
       case 1:q.addq();
	      break;
       case 2:q.delq();
	      break;
       case 3:q.display();
	      break;
       case 4:exit(0);
     }
     }
     return 0;
  }
