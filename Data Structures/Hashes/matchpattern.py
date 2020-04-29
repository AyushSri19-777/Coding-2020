"""Given a dictionary of words and a pattern. Every character in the pattern is uniquely mapped to a character in the dictionary. The task is to complete a function findMatchedWords(dict,pattern) that returns a vector of strings matching with given pattern. The function takes two argument the first argument is an array of strings dict which denote the dictionary and the second argument is the pattern to match.

Input:
The first line of input contains an integer T denoting the number of test cases. Each testcase contains 3 lines. The first line contains an integer N denoting the number of strings in the dictionary,second line N space separated strings denoting the strings of the dictionary. The third line contains pattern.

Output:
The output for each test case will be the space separated strings that matches the given pattern in lexicographical order.

User Task:
Since this is a functional problem you don't have to worry about input, you just have to complete the function findMatchedWords()

Constraints:
1 <= T <= 100
1 <= N <= 10

Input
1
4
abb abc xyz xyy
foo

Output
abb xyy

Explanation
Testcase 1: In the above test case xyy and abb have same character at index 1 and 2 like the pattern.
Link- https://practice.geeksforgeeks.org/problems/match-specific-pattern/1
"""
def findSpecificPattern(n, arr, string):
    dict={}
    h=[]
    f=[]
    for i in string:
        if i not in dict:
            dict[i]=1
        else:
            dict[i]=dict[i]+1
    h=list(dict.values())
    #print(h)
    for i in arr:
        dict2={}
        for j in i:
            if j not in dict2:
                dict2[j]=1
            else:
                dict2[j]=dict2[j]+1 
        u=list(dict2.values())
        #print(u)
        if u==h:
            f.append(i)
    return f
    
if __name__=='__main__':
    t = int(input())
    for i in range(t):
        n = int(input())
        arr = input().strip().split()
        string = input().strip()
        res = findSpecificPattern(n, arr, string)
        for i in res:
            print(i, end=" ")
        print('')