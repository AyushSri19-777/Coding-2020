"""
Given two strings a and b. The task is to find if a string 'a' can be obtained by rotating another string 'b' by 2 places.

Input:
The first line of input contains an integer T denoting the no of test cases. Then T test cases follow. In the next two line are two string a and b.

Output:
For each test case in a new line print 1 if the string 'a' can be obtained by rotating string 'b' by two places else print 0.

Constraints:
1 <= T <= 50
1 <= length of a, b < 100

Example:
Input:
2
amazon
azonam
geeksforgeeks
geeksgeeksfor

Output:
1
0

Explanation:
Testcase 1: amazon can be rotated anti-clockwise by two places, which will make it as azonam.

Testcase 2: geeksgeeksfor can't be formed by any rotation from the given word geeksforgeeks.
Link- https://practice.geeksforgeeks.org/problems/check-if-string-is-rotated-by-two-places/0/
"""
def Rrotate(s,n):
    return s[n-2:n]+s[0:n-2]
def Lrotate(s,n):
    return s[2:n]+s[0:2]
T=int(input())
for i in range (T):
    a=input()
    b=input()
    if a==Rrotate(b,len(b)) or a==Lrotate(b,len(b)):
        print(1)
    else:
        print(0)