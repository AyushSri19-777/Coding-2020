/*Find the missing element from  an ordered array A[ ], consisting of N elements representing an Arithmetic Progression (AP) .
 

Input:
The first line of input contains an integer T denoting the number of test cases. Then T test cases follow. 
The first line of each test case contains an integer N, where N is the size of the array A[ ].
The second line of each test case contains N space separated integers of an Arithmetic Progression denoting elements of the array A[ ].
 

Note: The series should have a missing element in between a perfect A.P. with no missing element will not be considered.
 

Output:
Print out the missing element. 
 

Constraints:
1 <= T <= 100
2 <= N <= 10
-50 <= A[i] <=50
 

Examples :

Input:
3
3 
2 10 14 
4 
-28 -21 -7 0 
5 
9 12 15 21 24

Output : 
6
-14
18 
*/
#include <iostream>
using namespace std;

int main() {
	int T,N,j,sum1=0,sum2=0;
	cin>>T;
	for(int i=0;i<T;i++)
	{
	    cin>>N;
	    sum1=0;
	    sum2=0;
	    int a[N];
	    for(j=0;j<N;j++)
	    {
	        cin>>a[j];
	        sum1+=a[j];
	    }
	   sum2=((N+1)*(a[0]+a[N-1]))/2;
	   //cout<<sum1<<"kitthe"<<sum2;
	    cout<<sum2-sum1<<"\n";
	}
	return 0;
}