/*
Given an integer n, return the least number of perfect square numbers that 
sum to n. A perfect square is an integer that is the square of an integer; 
in other words, it is the product of some integer with itself. 
For example, 1, 4, 9, and 16 are perfect squares while 3 and 11 are not.

Example 1:
Input: n = 12
Output: 3
Explanation: 12 = 4 + 4 + 4.

Example 2:
Input: n = 13
Output: 2
Explanation: 13 = 4 + 9.
 
Constraints:
1 <= n <= 104
*/

class Solution {
    int dp[10001];
    
public:
    int numSquares(int n) {
      for (int i=0; i<=10000; i++){
        dp[i] = 0;
      }
      for (int i=1; i<=100; i++){ // save perfect squares to dp (base cases)
        dp[i*i] = 1;
      }
      
      return bfs(n);
    }
  
    int bfs(int n){
      // check if it's in dp array
      if (dp[n] != 0){
        return dp[n];
      }
      
      // compute all paths, choose minimum (bfs)
      int newVal = 0;
      int min = 10000; // the value cannot exceed this value due to constraint
      for(int i=1; i*i<n; i++){ 
        newVal = bfs(n-i*i);
        dp[n-i*i] = newVal; //save computations to dp array along the way
        if(min > newVal){
          min = newVal;
        }
      }
      return min+1;
    }
};