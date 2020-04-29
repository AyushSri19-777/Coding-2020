#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;
int main()
{
 int i=0,j=0,k=0,count=0;
 int l=0,k1=0,cn[10],c=0;
 char a[80],b[80];
 cout<<"\nEnter main string:- \n";
 gets(a);
 cout<<"\nEnter sub-string:-\n";
 gets(b);
 l=strlen(b); //length of substring
while (a[i]!='\0')
 {//outer loop for MS
     if (a[i]==b[j])
        {
	i++;
	j++;
	k1=1; //character match flag
	if (j==l) { //check for all chars match
	    cn[c++]=i-l+1; //pos array 		              //with occurrence count in ‘c’
	    j=0;
	    k=1; //presence flag (SS)
	  }
      }
else {
       if (k1==1){
	   j=0;
	   k1=0; //flag reset
	  }
       else
	  i++;
    }
 } //end of while
if (k==1) {

cout<<"\nSubstring is present "<< c <<" time(s) at position(s)\t";
  for(i=0;i<c;i++)
     cout<<cn[i]<<"\t";
  }
 else   {
     if (k==0)
     cout<<"\nGiven sub-string is not present in the main string.";
  }
return 0;
}
