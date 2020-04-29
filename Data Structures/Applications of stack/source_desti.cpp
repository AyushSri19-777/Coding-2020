/*Mario wants to meet Pauline . Mario is standing at source point (x1 , y1) and Pauline is standing at destination point (x2 , y2 ) .Determine if it is possible to reach the destination point (x2, y2) from source point (x1 , y1) .
Note: Mario has only two valid moves :
(x1 , y1 ) to ( x1 + y1 , y1 ) 
(x1 , y1)  to  ( x1 , y1 + x1)

Input:
First line of input consists of an integer T representing number of test cases. For each test case first line contains four space seperated intergers denoting coordiates of source and destination point.
Output:
For each test case print True if Mario can reach Pauline else print False.
Your Task:
Since it is a functional problem , you just have to complete the function isPossible() which accepts four integer values denoting coordinates of source and destination point and returns a boolean value.
Constraints:
1 <= T <= 100
1 <= x1 , y1 , x2 , y2 <= 20
Example:
Input:
2
3 2 5 7
1 2 3 4
Output:
True
False*/
bool isPossible(int sx, int sy, int dx, int dy) 
{ 
    if (sx > dx || sy > dy) 
        return false; 
  
    if (sx == dx && sy == dy) 
        return true; 
  
    return (isPossible(sx + sy, sy, dx, dy) ||  
            isPossible(sx, sy + sx, dx, dy)); 

}