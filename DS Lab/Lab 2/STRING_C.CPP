#include <iostream.h>
#include <conio.h>
#include <string.h>
#include <stdio.h>
int main()
{
   clrscr();
   char s1[30],s2[30];
   int i,j,r=0,d=0;
   cout<<"Enter a string\n";
   gets(s1);
   //length calculated
   for(i=0;s1[i]!='\0';i++);
   cout<<"The length of 1st string is "<<i;
   cout<<"\nEnter the second string\n";
   gets(s2);
   for(j=0;s2[j]!='\0';j++);
   //concatenation
   for(int k=i;k<i+j;k++)
   {
       s1[k]=s2[r++];
   }
   cout<<"The concatenated string\n";
   for(int h=0;h<i+j;h++)
   cout<<s1[h];
   //comparison
   for(k=0;k<(i>j)?i:j;k++)
   {
     d=s1[k]-s2[k];
     if(d!=0)
     break;
   }
   cout<<"\nstring 1 compared to string 2 results in "<<d;
   getch();
   cout<<"Enter the position and substring you want to insert\n";
   return 0;
 }