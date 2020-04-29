"""Arya has a string, S, of uppercase English letters. She writes down the string S on a paper K times.
She wants to calculate the occurence of a specific letter in the first N characters of the final string.

Input:

First line of input contains a single integer T denoting the number of test cases.
The first line of each test case contains a string S.
The second line contains 2 space-separated integers K and N, and an uppercase English letter C whose occurence needs to be counted.

Output:

For each test case, print the required answer in a new line.


Constraints:

1 <= T <= 150
1 <= |S| <= 500
1 <= K <= 10^5
1 <= N <= |S|*K


Example:

Input : 
2
ABA
3 7 B
BHD
4 6 E
Output : 
2
0

Explaination : 
Case 1 : Final string - ABAABAABA
Case 2 : Final string - BHDBHDBHDBHD

Example 2 :
Input : 
1
MMM
2 4 M
Output :
4

Explaination : 
Case 1 : Final string - MMMMMM
Link- https://practice.geeksforgeeks.org/problems/aryas-long-string/0/
"""
T=int(input())
for i in range (T):
    S=input()
    a=input()
    g=0
    w=""
    a=a.split(" ")
    b=int(a[0])
    c=int(a[1])
    for j in range (b):
        w=w+S
    w=w[0:c]
    print(len(w.split(a[2]))-1)

    