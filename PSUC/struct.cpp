#include<iostream>
#include<stdio.h>
using namespace std;
struct stud{
  int rollno;
  char name[];
  int marks[3];
};
int main()
{
    stud s[3];
    int lar=0,i,j,c=0,mean,pos;
    for(i=0;i<3;i++)
    {
       cout<<"\nEnter name, marks in 3 subjects and rollno. of student "<<(i+1)<<"\n";
        gets(s[i].name);
        for(j=0;j<3;j++)
        {
             cin>>s[i].marks[j];
             c=c+s[i].marks[j];
        }
        cout<<c;
        cin>>s[i].rollno;
        mean=c/3;
        if(mean>lar)
        {
            lar=mean;
            pos=i;
        }
        c=0;
        cout<<lar;

    }
    cout<<"Highest Average is of :";
    cout<<"Name :";
    puts(s[pos].name);
    cout<<"Roll No."<<s[pos].rollno;
    cout<<"His Marks: ";
    for(i=0;i<3;i++)
        cout<<"Subject"<<(i+1)<<":\t"<<s[pos].marks[i]<<"\n";
    return 0;

}
