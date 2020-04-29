#include <iostream>
using namespace std;
class sparse
{
    int r,c,v;
public:
    void read(sparse *);
    void trans(sparse *,sparse *);
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
void sparse::display(sparse a[])
{
    int i;
    cout<<"Row\tColumn\tValue\n";
    for(i=0;i<=a[0].v;i++)
        cout<<a[i].r<<"\t"<<a[i].c<<"\t"<<a[i].v<<"\n";
}
void sparse::trans(sparse a[],sparse b[])
{
    int i,j,n,k=1;
    n=a[0].v;
    b[0].c=a[0].r;
    b[0].r=a[0].c;
    b[0].v=n;
    for(i=0;i<a[0].c;i++)//to run loop in ascending order
    {
        for(j=1;j<=n;j++)//to traverse column of 1st(original) matrix
        {
            if(a[j].c==i)//to check if row element is smallest
            {
                b[k].c=a[j].r;
                b[k].r=a[j].c;
                b[k].v=a[j].v;
                k++;
            }
        }
    }
}
int main()
{
    sparse s,s1[10],s2[10];
    s.read(s1);
    cout<<"Before transpose:\n";
    s.display(s1);
    s.trans(s1,s2);
    cout<<"After transpose:\n";
    s.display(s2);
    return 0;
}
