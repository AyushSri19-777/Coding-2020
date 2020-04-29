#include <bits/stdc++.h>
using namespace std;
int i,N,Arr[100];
void input()
{

    cout<<"Enter the size of heap array";
    cin>>N;
    cout<<"Enter a unsorted heap";
    for(i=1;i<=N;i++)
    {
        cin>>Arr[i];
    }
}
void max_heapify(int Arr[],int i,int N)
{
    int left=2*i,largest;
    int right=2*i+1;

    if(left<=N&&Arr[left]>Arr[i])
        largest=left;
    else
        largest=i;
    if(right<=N&&Arr[right]>Arr[largest])
        largest=right;
    if(largest!=i)
    {
        int t;
        t=Arr[i];
        Arr[i]=Arr[largest];
        Arr[largest]=t;
        max_heapify(Arr,largest,N);
    }
}
void display()
{
    cout<<"The heap is";
    int i;
    for(i=1;i<=N;i++)
    {
        cout<<Arr[i]<<" ";
    }
}

int main()
{
    input();
    display();
    max_heapify(Arr,1,N);
    display();
}
