
#include <iostream>
using namespace std;
int main()
{

    char s[]="12abc",x;
    int *ptr;
    ptr=(int *)s+2;
    x=(int)*ptr-(int)*s;
    cout<<(int)x;
    //cout<<sizeof(x);
    return 0;
}
