#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;
class fully
{
    char stk[25][25],infix[50],pfix[50],op1[20],op2[20],res[30];
    int top;
public:
    void push(char *);
    char *pop();
    void convert();
    void read();
    fully()
    {
       top=-1;
    }
};
void fully::push(char a[])
{
    strcpy(stk[++top],a);
}
char* fully::pop()
{
    return stk[top--];
}
void fully:: convert()
{
    int c=0;
    char sym[2];
    while(pfix[c]!='\0')
    {
        sym[0]=pfix[c];
        sym[1]='\0';
        if(sym[0]=='+'||sym[0]=='-'||sym[0]=='*'||sym[0]=='/')
        {
            strcpy(op2,pop());
            strcpy(op1,pop());
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
    puts(res);
}
void fully::read()
{
    cout<<"Enter the postfix expression: ";
    gets(pfix);
}
int main()
{
    fully f;
    f.read();
    cout<<"The fully paranthesized infix exp : ";
    f.convert();
    return 0;
}
