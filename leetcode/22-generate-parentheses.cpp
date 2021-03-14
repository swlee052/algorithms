/*
Given n pairs of parentheses, write a function to generate all combinations 
of well-formed parentheses.

Example 1:
Input: n = 3
Output: ["((()))","(()())","(())()","()(())","()()()"]

Example 2:
Input: n = 1
Output: ["()"]

Constraints:
1 <= n <= 8
*/

class Solution {
public:
    vector<string> generateParenthesis(int n) {
      vector<string> ans;

      //recurse
      add(ans, "(", n, 1, 1);
      return ans;
    }
  
    void add(vector<string>& ans, string s, int n, int numLeft, int diff){
      if(numLeft == n && diff == 0){
        ans.push_back(s);
        return;
      }
      
      if(numLeft < n){
        add(ans, s + "(", n, numLeft+1, diff+1);
      }
      if(diff > 0){
        add(ans, s + ")", n, numLeft, diff-1);
      }   
    }
};