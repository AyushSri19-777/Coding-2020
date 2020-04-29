#include<iostream>
using namespace std;
int main()
{
   char name[15];
   char *cptr=name;
   cout<<"Enter some word to find its length"<<endl;
   cin>>name;
   while(*cptr!= '\0')
		cptr++;
   cout<<"length="<<cptr-&name[0];
   return 0;
}
