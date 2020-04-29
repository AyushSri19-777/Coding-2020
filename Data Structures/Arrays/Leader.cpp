#include <iostream>
using namespace std;
int main() {
	int T,N,j,p=0,k=0;
	cin>>T;
	for(int i=0;i<T;i++)
	{
	    cin>>N;
	    int a[N];
	    for(j=0;j<N;j++)
	        cin>>a[j];
	    int t=a[N-1];
	    for(j=N-2;j>=0;j--)
	    {
	        if(t<=a[j])
	        {
	            cout<<t<<" ";
	            t=a[j];
	        }
	    }
        cout<<t;
	}
	return 0;
}