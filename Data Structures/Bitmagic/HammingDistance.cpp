/*The Hamming distance between two integers is the number of positions at which the corresponding bits are different.

Given two integers x and y, calculate the Hamming distance.

Note:
0 ≤ x, y < 231.

Example:

Input: x = 1, y = 4

Output: 2

Explanation:
1   (0 0 0 1)
4   (0 1 0 0)
       ↑   ↑

The above arrows point to positions where the corresponding bits are different.
Link- https://leetcode.com/explore/featured/card/july-leetcoding-challenge/544/week-1-july-1st-july-7th/3381/
*/
#include <iostream>
using namespace std;
int hammingDistance(int x, int y) {
        int res=x^y;
        int count=0;
        while(res!=0)
        {
            count+=(res&1);
            res>>=1;
        }
        return count;
        
}
int main()
{
    cout<<"Enter two numbers to get hamming distance\n";
    int x,y;
    cin>>x>>y;
    cout<<"Hamming distance= "<<hammingDistance(x,y);
}