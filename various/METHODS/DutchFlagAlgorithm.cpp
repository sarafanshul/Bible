/* 
Dutch national flag problem


The Dutch national flag
The Dutch national flag problem [1] is a computer science programming 
problem proposed by Edsger Dijkstra.[2] The flag of the Netherlands 
consists of three colors: red, white and blue. Given balls of these 
three colors arranged randomly in a line (the actual number of balls 
does not matter), the task is to arrange them such that all balls 
of the same color are together and their collective color groups are 
in the correct order.

The solution to this problem is 
of interest for designing sorting algorithms; 
in particular, variants of the quicksort algorithm 
that must be robust to repeated elements may use a 
three-way partitioning function that groups items less than 
a given key (red), equal to the key (white) and greater than 
the key (blue). Several solutions exist that have varying 
performance characteristics, tailored to sorting arrays with 
either small or large numbers of repeated elements.[3] 

Pseudocode
The following pseudocode for three-way 
partitioning assumes zero-based array indexing. 
It uses three indices i, j and k, maintaining the 
invariant that i ≤ j ≤ k.

Entries from 0 up to (but not including) i are values less than mid,
entries from i up to (but not including) j are values equal to mid,
entries from j up to (but not including) k are values not yet sorted, and
entries from k to the end of the array are values greater than mid.



procedure three-way-partition(A : array of values, mid : value):
    i ← 0
    j ← 0
    k ← size of A

    while j < k:
        if A[j] < mid:
            swap A[i] and A[j]
            i ← i + 1
            j ← j + 1
        else if A[j] > mid:
            k ← k - 1
            swap A[j] and A[k]
        else:
            j ← j + 1

eg -> https://leetcode.com/problems/sort-colors/
*/

class Solution {
    public:
    void sortColors(vector<int>& nums) {
        long tmp = 0, low = 0, mid = 0, high = nums.size() - 1;
        while(mid <= high) {
            if(nums[mid] < 1) {
                tmp = nums[low];
                nums[low] = nums[mid];
                nums[mid] = tmp;
                low++;
                mid++; }
            else if(nums[mid] > 1) {
                tmp = nums[high];
                nums[high] = nums[mid];
                nums[mid] = tmp;
                high--; }
            else mid++;
        }
    }
};