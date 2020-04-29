#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;
class pre2post
{
    char stk[30][30],pre[50],op1[25],op2[25],top,res[50];
public:
    void input();
    void push(char *);
    char *pop();
    void convert();
    pre2post()
    {
        top=-1;
    }
};
void pre2post::input()
{
    cout<<"Enter the prefix expression: ";
    gets(pre);
    strrev(pre);
    cout<<"The equivalent postfix expression: \n ";
}
void pre2post::push(char a[])
{
    strcpy(stk[++top],a);
}
char *pre2post::pop()
{
    return stk[top--];
}
void pre2post:: convert()
{
    int c=0; char sym[2];
    while(pre[c]!='\0')
    {
        sym[0]=pre[c];
        sym[1]='\0';
        if(sym[0]=='+'||sym[0]=='-'||sym[0]=='*'||sym[0]=='/')
        {
            strcpy(op1,pop());
            strcpy(op2,pop());
            strcpy(res,op1);
            strcat(res,op2);
            strcat(res,sym);
            push(res);
        }
        else
            push(sym);


        c++;
    }
    puts(res);
}
int main()
{
    pre2post ob;
    ob.input();
    ob.convert();
    return 0;
}
