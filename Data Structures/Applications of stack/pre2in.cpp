#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;
class pre2in
{
    char stk[30][30],pre[50],res[50],op1[25],op2[25],top;
public:
    void push(char *);
    char *pop();
    void convert();
    void input();
    pre2in()
    {
        top=-1;
    }
};
void pre2in::input()
{
    cout<<"Enter the prefix expression: ";
    gets(pre);
    strrev(pre);
    cout<<"The equivalent infix expression is: ";
}
char *pre2in::pop()
{
    return stk[top--];
}
void pre2in::push(char a[])
{
    strcpy(stk[++top],a);
}
void pre2in::convert()
{
    int c=0;
    char sym[2];
    while(pre[c]!='\0')
    {
        sym[0]=pre[c];
        sym[1]='\0';
        if(sym[0]=='+'||sym[0]=='-'||sym[0]=='*'||sym[0]=='/')
        {
            strcpy(op1,pop());
            strcpy(op2,pop());
            strcpy(res,"(");
            strcat(res,op1);
            strcat(res,sym);
            strcat(res,op2);
            strcat(res,")");
            push(res);
        }
        else
            push(sym);
        c++;
    }
    cout<<pop();
}
int main()
{
    pre2in p;
    p.input();
    p.convert();
    return 0;
}
