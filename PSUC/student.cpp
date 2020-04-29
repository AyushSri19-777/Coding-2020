#include <bits/stdc++.h>
using namespace std;
class student
{
    int roll;
    char grade;
    char name[30];
    public:
    void read();
    void display();
    void sorty(student *,int);
};
void student::read()
{
    cout<<"Enter the name :";
    cin>>name;
    cout<<"Enter the roll no.: ";
    cin>>roll;
    cout<<"Enter the grade : ";
    cin>>grade;
}
void student::display()
{
    cout<<"\nName : ";
    puts(name);
    cout<<"Roll No. : "<<roll;
    cout<<"\nGrade : "<<grade;
}
void student::sorty(student ob[],int n)
{
    student temp;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n-1;j++)
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
    int n,i;
    student s[10],s1;
    cout<<"Enter the number of students:";
    cin>>n;
    for(i=0;i<n;i++)
        s[i].read();
    cout<<"\nThe details before sort";
    for(i=0;i<n;i++)
        s[i].display();
    s1.sorty(s,n);
    cout<<"\nThe details after sort";
    for(i=0;i<n;i++)
        s[i].display();
    return 0;

}
