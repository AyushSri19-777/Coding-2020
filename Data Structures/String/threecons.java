/*Ishaan is playing with strings these days. He has found a new string. He wants to modify it as per the following rules :

The string should not have three consecutive same characters (Refer example for explanation).
He can add any number of characters anywhere in the string. Find the minimum number of characters which Ishaan must insert in the string.
Input: 
First line of input contains a single integer T denoting the number of test cases.The only line of each test case contains a string S consisting of lowercase English Alphabets.

Output: 
For each test case, in a new line,  print the required answer in a new line.

Your Task:
This is a function problem. You only need to complete the function modified that returns the answer.

Constraints : 
1 <= T <= 200
1 <= Length of S <= 103

Example : 
Input : 
3
aabbbcc
aaaaa
abcddee
Output : 
1
2
0

Explanation : 
Testcase 1 : In aabbbcc 3 b's occur consecutively, we add a 'd',and Hence, output will be aabbdbcc.
Testcase 2 : In aaaaa 5 a's occur consecutively, we need to add 2 'b',and Hence, output will be aababaa.
Testcase 3 : In abcddee , No character occurs 3 times, so no need to add anything.
 

** For More Input/Output Examples Use 'Expected Output' option **
Author: goyalanubhav11
Link-https://practice.geeksforgeeks.org/problems/the-modified-string/1

*/

class solve{
    public static long modified(String a){
        int same=1,c=0;
        char b=a.charAt(0);
        for(int i=1;i<a.length();i++)
        {
            if(b==a.charAt(i))
            {
                same++;
                if(same==3)
                {
                    same=1;
                    c++;
                }
            }
            else
            {
                b=a.charAt(i);
                same=1;
            }
        }
        return c;
    }
}