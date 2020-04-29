#include<bits/stdc++.h>
using namespace std;
int main()
{
    int i,ch,ptr;
     ptr=0;
    do{
         cout<<"\nEnter the choice you want to go and press 55 to stop\n";
         cin>>ch;
         ptr+=ch;
         if(ptr<0||ptr>50)
         {
           cout<<"Lift movement not possible\n";
           ptr-=ch;
           continue;
         }
         else if(ch==55)
            break;
         else
         cout<<"Current floor= "<<ptr;
    }while(ch!=55);
    return 0;
}
