"""Given an array of names (consisting of lowercase characters) of candidates in an election. A candidate name in array represents a vote casted to the candidate. Print the name of candidate that received Max votes. If there is tie, print lexicographically smaller name.

Input:
The first line of the input contains a single integer T, denoting the number of test cases. Then T test case follows. Each testcase contains two lines input. First line is the number of votes cast N.And second line is the name of the candidates separated by a space. Each name represents one vote casted to that candidate.

Output:
For each testcase, print the name of the candidate with the maximum votes, and also print the votes casted for the candidate. The name and votes are separated by a space.

Your Task:
This is a functional problem. You only need to complete the function winnter() that takes an array of strings arr, and n as parameters and prints the candiate with maximum votes. Newline is automatically appended by the driver code.

Constraints:
1 <= T <= 100
1 <= N <= 105

Example:
Input:
2
13
john johnny jackie johnny john jackie jamie jamie john johnny jamie johnny john
3
andy blake clark
Output:
john 4
andy 1

Explanation:
Testcase1: john has 4 votes casted for him, but so does johny. john is lexicographically smaller, so we print john and the votes he received.
Testcase2: All the candidates get 1 votes each. We print andy as it is lexicographically smaller.
Link- https://practice.geeksforgeeks.org/problems/winner-of-an-election-where-votes-are-represented-as-candidate-names/1
"""
#User function Template for python3

#Complete this function
def winner(arr,n):
    dicta,seat={},{}
    a,d=[],[]
    max=0
    j=0
    for i in arr:
        if i in dicta:
            dicta[i]=dicta[i]+1
        else:
            dicta[i]=1
    for i in dicta:
        a.append(i)
        if dicta[i]>max:
            max=dicta[i]
    for i in dicta:
        if max == dicta[i]:
            seat[i]=max
    if max==1:
        s=sorted(a)
        k=s[0]+" 1"
    else:
        d=sorted(seat)
        k=d[0]+" "+str(dicta[d[0]])
    print(k, end = '')    

def main():
    T=int(input())
    while(T>0):
        
        n=int(input())
        arr=input().strip().split()
        
        winner(arr,n)
        print()
        
        T-=1

if __name__=="__main__":
    main()
