/*
Given a string s and an integer k, reverse the first k characters for every 
2k characters counting from the start of the string.

If there are fewer than k characters left, reverse all of them. If there are 
less than 2k but greater than or equal to k characters, then reverse the 
first k characters and left the other as original.

Example 1:
Input: s = "abcdefg", k = 2
Output: "bacdfeg"

Example 2:
Input: s = "abcd", k = 2
Output: "bacd"
 
Constraints:
1 <= s.length <= 104
s consists of only lowercase English letters.
1 <= k <= 104
*/

class Solution {
public:
    string reverseStr(string s, int k) {
      string ans = s;
      int sz = s.length();
      
      if(sz < k){
        for(int i=0; i<sz/2; i++){
          swap(ans, i, sz-1-i);
        }
      }
      
      else{
        for(int i=0; i<sz; i+= 2*k){
          int minVal = min(sz-i, k);
          for(int j=0; j<minVal/2; j++){
            swap(ans, i+j, i+minVal-1-j);
          }
        }
      }
      return ans;
    }
  
    void swap(string& s, int i, int j){
      char tmp = s[i];
      s[i] = s[j];
      s[j] = tmp;
    }
};
