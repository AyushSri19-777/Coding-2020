#include <iostream>
using namespace std;
class sparse
{
    int r,c,v;
public:
    void read(sparse *);
    void ftrans(sparse *,sparse *);
    void display(sparse *);
    sparse()
    {
        r=0;
        c=0;
        v=0;
    }

};
void sparse::read(sparse a[])
{
    int m,n,i,j,k=1,val;

    cout<<"Enter the size of matrix:\n";
    cin>>m>>n;
    a[0].r=m;
    a[0].c=n;
    cout<<"Enter the elements:\n";
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            cin>>val;
            if(val!=0)
            {
                a[k].r=i;
                a[k].c=j;
                a[k].v=val;
                k++;
            }
        }
    }
    a[0].v=k-1;
}
void sparse::display(sparse x[])
{
    int i;
    cout<<"\nRow\tColumn\tValue\n";
    for(i=0;i<=x[0].v;i++)
        cout<<x[i].r<<"\t"<<x[i].c<<"\t"<<x[i].v<<"\n";
}
void sparse::ftrans(sparse a[],sparse b[])
{
    int i,j,k=1;
    int rT[100],sp[100];
    sp[0]=1;
    b[0].c=a[0].r;
    b[0].r=a[0].c;
    for(i=0;i<=a[0].c;i++)
        rT[i]=0;    //initializing the counter
    for(i=1;i<=a[0].v;i++)
        rT[a[i].c]++;   // increasing the values according to number of occurances
    for(i=1;i<=a[0].c;i++)
       sp[i]=sp[i-1]+rT[i-1];
   for(i=1;i<=a[0].v;i++)
    {
        j=sp[a[i].c]++;
        b[j].r=a[i].c;
        b[j].c=a[i].r;
        b[j].v=a[i].v;
        k++;
        }
    b[0].v=k-1;
}
int main()
{
    sparse s,s1[10],s2[10];
    s.read(s1);
    cout<<"Before transpose:\n";
    s.display(s1);
    cout<<"After transpose:\n";
    s.ftrans(s1,s2);
    s.display(s2);
    return 0;
}

