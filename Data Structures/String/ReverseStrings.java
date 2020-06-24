import java.util.StringTokenizer;

/*Reverse words in a given string 
Given a String of length S, reverse the whole string without reversing the individual words in it. Words are separated by dots.

Input:
The first line contains T denoting the number of testcases. T testcases follow. Each case contains a string S containing characters.

Output:
For each test case, in a new line, output a single line containing the reversed String.

User Task:
The task is to complete the function reverseWords() which reverse words from the given string and prints the answer. The newline is automatically appended by the driver code.

Expected Time Complexity: O(|S|)
Expected Auxiliary Space: O(1)

Constraints:
1 <= T <= 100
1 <= |S| <= 2000

Example:
Input:
2
i.like.this.program.very.much
pqr.mno
Output:
much.very.program.this.like.i
mno.pqr

Explanation:
Testcase 1: After reversing the whole string(not individual words), the input string becomes much.very.program.this.like.i.
Testcase 2: After reversing the whole string , the input string becomes mno.pqr.
Link- 
*/
class Reverse {

    public static void reverseWords(String s) {
        String w="";
        StringTokenizer st=new StringTokenizer(s,".");
        while(st.hasMoreTokens())
        {
            String k=st.nextToken();
            w=k+"."+w;
        }
        w=w.substring(0,w.length()-1);
        System.out.print(w);
    }
}