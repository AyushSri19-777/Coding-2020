/*You are given an array arr[] of N integers including 0. The task is to find the smallest positive number missing from the array.
Note: Expected solution in O(n) time using constant extra space.

Input:
First line consists of T test cases. First line of every test case consists of N, denoting the number of elements in array. Second line of every test case consists of elements in array.

Output:
Single line output, print the smallest positive number missing.

Constraints:
1 <= T <= 100
1 <= N <= 106
-106 <= arr[i] <= 106

Example:
Input:
2
5
1 2 3 4 5
5
0 -10 1 3 -20
Output:
6
2

Explanation:
Testcase 1: Smallest positive missing number is 6.
Testcase 2: Smallest positive missing number is 2.
*/
#include <iostream>
using namespace std;

int main() {
	int T;
	cin>>T;
	for(int i=0;i<T;i++)
	{
	    int n,a,k=0,max=0,f=0,j;
	    cin>>n;
	    int b[n];
	    for(j=0;j<n;j++)
	    {
	        cin>>a;
	        if(a>=0)
	        {
	            b[k++]=a;
	            if(max<a)
	                max=a;
	        }
	    }
        //cout<<"max"<<max<<"\n";
        j=0;
        int d[max];
	    while(j!=max)
	    {
            f=b[j++];
            //cout<<"f bole toh "<<f<<"\n";
	        d[f]=f;
	    }
        //cout<<d[2]<<"d bole toh";
        for(j=1;j<max;j++)
        {
            if(d[j]!=j)
               break;   
        }
        if(max==j)
            cout<<j+1;
        else
        {
            cout<<j;
        }
        
	}
	return 0;
}