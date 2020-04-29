/*John's school has been cancelled due to the Corona Pandemic for a few weeks. He is stuck at home and his mother has given him the task of arranging all his tshirts in sorted order. He has N tshirts all of which are denoted by a distinct numeric value. But John is lazy and wants to be done with this task as soon as possible. Help John find a sub array in the given order of tshirts, such that reversing the subarray will be sufficient to arrange all his tshirts in sorted order.

Input:
The first line of input contains the number of testcases T. The first and only line of every testcase contains an integer N for the number of tshirts followed by N space separated integers denoting their current order.

Output: 
Return true if a sorted array is possible otherwise return false.

Your Task:
You don't have to take input. Complete the function SortedArray() that takes array arr and n as parameter and return the true or flase. The printing is done by the driver code.

Constraints:
1<= T <= 50
1 <= N <= 102

Example:
Input:
2
5 1 2 5 4 3
5 1 2 4 5 3
Output:
Yes
No

Explanation:
Testcase 1: Reverse the subarray {5, 4, 3} to get the sorted array {1, 2, 3, 4, 5}.
Testcase 2: No matter what subarray you reverse, the original array will never be sorted.*/
// C++ program to check whether reversing a 
// sub array make the array sorted or not 
#include<bits/stdc++.h> 
using namespace std; 
  
// Return true, if reversing the subarray will 
// sort the array, else return false. 
bool checkReverse(int arr[], int n) 
{ 
    // Copying the array. 
    int temp[n]; 
    for (int i = 0; i < n; i++) 
        temp[i] = arr[i]; 
  
    // Sort the copied array. 
    sort(temp, temp + n); 
  
    // Finding the first mismatch. 
    int front; 
    for (front = 0; front < n; front++) 
        if (temp[front] != arr[front]) 
            break; 
  
    // Finding the last mismatch. 
    int back; 
    for (back = n - 1; back >= 0; back--) 
        if (temp[back] != arr[back]) 
            break; 
  
    // If whole array is sorted 
    if (front >= back) 
        return true; 
  
    // Checking subarray is decreasing or not. 
    do
    { 
        front++; 
        if (arr[front - 1] < arr[front]) 
            return false; 
    } while (front != back); 
  
    return true; 
} 
  
// Driven Program 
int main() 
{ 
    int arr[] = { 1, 2, 5, 4, 3 }; 
    int n = sizeof(arr)/sizeof(arr[0]); 
  
    checkReverse(arr, n)? (cout << "Yes" << endl): 
                          (cout << "No" << endl); 
    return 0; 95507859
} 