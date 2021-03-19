/*
Given a non-empty string s, you may delete at most one character. Judge 
whether you can make it a palindrome.

Example 1:
Input: "aba"
Output: True

Example 2:
Input: "abca"
Output: True
Explanation: You could delete the character 'c'.

Note:
The string will only contain lowercase characters a-z. The maximum length of 
the string is 50000.
*/

class Solution {
public:
    bool validPalindrome(string s) {
      bool chance = true;
      return check(s, chance);
    }
    
    bool check(string s, bool& chance){
      int sz = s.length();
      
      for(int i=0; i<sz/2; i++){
        if(s[i] != s[sz-1-i]){
          if(chance){
            chance = false;
            return check(s.substr(i+1, sz-2*i-1), chance) 
                    || check(s.substr(i, sz-2*i-1), chance);
          }
          else {
            return false;
          }
        }
      }
      return true;
    }
};

// abcdba
// 1    1
//  1  1
//   11
//    1 