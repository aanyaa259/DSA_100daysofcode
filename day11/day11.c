/*100 Days DSA Challenge 🚀
Master Data Structures & Algorithms

Next Day Unlocks In
22:49:41
📚 How to Use This Challenge
👉 ℹ️ Watch this quick video tutorial to learn how to make the most of your 100-day journey!
👉 ℹ️ For Optimal Solution Of Plateform Specific Problems, Watch Tutorial Video Attached!
Watch Instructions
12
Unlocked
9
Completed
7
Day Streak
Search by day, question, or topic...
All
Introduction
Linked List
Stack/Queue
Trees
Hash/Graph
Sort/Search
✓ Unlocked
Day 1
I: Introduction
Array Basics
Hash Tables
Question 1 - C Programming
Practice
Insert an Element in an Array
View Problem →
Question 2 - LeetCode
Easy
Two Sum
Solve Problem →
Completed

✓ Solutions Available




















✓ Unlocked
Day 2
I: Introduction
Array Operations
Math
Question 1 - C Programming
Practice
Delete an Element from an Array
View Problem →
Question 2 - LeetCode
Easy
Best Time to Buy and Sell Stock
Solve Problem →
Completed

✓ Solutions Available



















✓ Unlocked
Day 3
I: Introduction
Array Searching
Question 1 - C Programming
Practice
Linear Search with Comparison Count
View Problem →
Question 2 - GeeksforGeeks
Easy
Missing number in array
Solve Problem →
Mark as Complete

✓ Solutions Available




















✓ Unlocked
Day 4
I: Introduction
Array Reversal
Two Pointers
Question 1 - C Programming
Practice
Reverse an Array In-Place
View Problem →
Question 2 - LeetCode
Easy
Remove Element
Solve Problem →
Completed

✓ Solutions Available





















✓ Unlocked
Day 5
I: Introduction
Array Merge
Two Pointers
Question 1 - C Programming
Practice
Arrange Arrival Logs
View Problem →
Question 2 - LeetCode
Easy
Merge Sorted Array
Solve Problem →
Completed

✓ Solutions Available





















✓ Unlocked
Day 6
I: Introduction
Array Cleanup
Question 1 - C Programming
Practice
Remove Duplicates from Sorted Array
View Problem →
Question 2 - LeetCode
Easy
Move Zeroes
Solve Problem →
Completed

✓ Solutions Available





















✓ Unlocked
Day 7
I: Introduction
Recursion
Question 1 - C Programming
Practice
Recursive Fibonacci
View Problem →
Question 2 - LeetCode
Easy
Fibonacci Number
Solve Problem →
Completed

✓ Solutions Available























✓ Unlocked
Day 8
I: Introduction
Recursion
Math
Question 1 - C Programming
Practice
Compute Power Using Recursion
View Problem →
Question 2 - LeetCode
Easy
Power of Two
Solve Problem →
Completed

✓ Solutions Available























✓ Unlocked
Day 9
I: Introduction
String
Two Pointers
Question 1 - C Programming
Practice
Mirror the Code Name
View Problem →
Question 2 - LeetCode
Easy
Reverse String
Solve Problem →
Completed

✓ Solutions Available





















✓ Unlocked
Day 10
I: Introduction
Palindrome Check
Array
Question 1 - C Programming
Practice
Check Palindrome
View Problem →
Question 2 - LeetCode
Easy
Intersection of two arrays
Solve Problem →
Completed

✓ Solutions Available


























✓ Unlocked
Day 11
I: Introduction
Matrix
Question 1 - C Programming
Practice
Matrix Addition
View Problem →
Question 2 - LeetCode
Easy
Transpose Matrix
Solve Problem →
Mark as Complete

✓ Solutions Available
























🔥 Today's Challenge
Day 12
I: Introduction
Matrix Diagonal
Question 1 - C Programming
Practice
Check Symmetric Matrix
View Problem →
Question 2 - LeetCode
Easy
Toeplitz Matrix
Solve Problem →
Mark as Complete

🔒 Solutions unlock when Day 13 opens (Feb 13, 2026 at 07:00)
🔒 Day 13 Locked
Next challenge unlocks on
Friday, February 13, 2026
at 07:00 Asia/Kolkata
22:49:41
Your Progress
9 / 12 Days
Day 11 - Question 1: Matrix Addition
Close
Problem: Write a program to perform addition of two matrices having the same dimensions. The sum of two matrices is obtained by adding corresponding elements of the matrices.

Input:
- First line: two integers m and n representing the number of rows and columns
- Next m lines: n integers each representing the elements of the first matrix
- Next m lines: n integers each representing the elements of the second matrix

Output:
- Print the resultant matrix after addition, with each row on a new line and elements separated by spaces

Example:
Input:
3 3
1 2 3
4 5 6
7 8 9
9 8 7
6 5 4
3 2 1

Output:
10 10 10
10 10 10
10 10 10

Explanation:
Each element of the result matrix is the sum of the corresponding elements from the two input matrices.

Test Cases:

Test Case 1:
Input:
2 2
1 2
3 4
5 6
7 8
Output:
6 8
10 12

Test Case 2:
Input:
1 3
10 20 30
1 2 3
Output:
11 22 33

Test Case 3:
Input:
3 1
1
2
3
4
5
6
Output:
5
7
9*/
#include <stdio.h>

int main() {
    int m, n;

    if (scanf("%d %d", &m, &n) != 2) return 0;

    int matrix1[m][n];
    int matrix2[m][n];

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matrix1[i][j]);
        }
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matrix2[i][j]);
        }
    }

    

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d", matrix1[i][j] + matrix2[i][j]);
            if (j < n - 1) {
                printf(" ");
            }
        }
        printf("\n");
    }

    return 0;
}