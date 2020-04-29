#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;
class student
{
  int roll;
  char grade;
  char name[30];
  public:
   void read();
   void sorte(student *,int );
   void display();
};
void student ::read()
{
   cout<<"\nEnter the name: ";
   gets(name);
   cout<<"\nEnter the roll no.: ";
   cin>>roll;
   cout<<"\nEnter the grade: ";
   cin>>grade;
}
void student:: display()
{
   cout<<"Name : ";
   puts(name);
   cout<<"Roll No.: "<<roll;
   cout<<"Grad: "<<grade;
}
void student:: sorte(student ob[],int n)
{
    int i,j;
    student temp;
    for(i=0;i<=n;i++)
    {
       for(j=0;j<=n-1;j++)
       {
	  if(ob[j].roll>ob[j+1].roll)
	  {
	       temp=ob[j];
	       ob[j]=ob[j+1];
	       ob[j+1]=temp;
	  }
       }
     }
}
int main()
{
  student s[10],s1;
  int n,i;
  cout<<"Enter the number of students";
  cin>>n;
  for(i=0;i<n;i++)
  s[i].read();
  cout<<"The details:\n ";
  for(i=0;i<n;i++)
  s[i].display();
  s1.sorte(s,n);
  cout<<"\nThe sorted details:\n";
  for(i=0;i<n;i++)
  s[i].display();
  return 0;
  }
