/*
Given a string containing digits from 2-9 inclusive, return all possible
letter combinations that the number could represent. Return the answer in any 
order.

A mapping of digit to letters (just like on the telephone buttons) is given 
below. Note that 1 does not map to any letters.

Example 1:
Input: digits = "23"
Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]

Example 2:
Input: digits = ""
Output: []

Example 3:
Input: digits = "2"
Output: ["a","b","c"]
 

Constraints:
0 <= digits.length <= 4
digits[i] is a digit in the range ['2', '9'].
*/

class Solution {
  vector<string> ans;
  int digitLen;
public:
    vector<string> letterCombinations(string digits) {
      digitLen = digits.length();
      if (digitLen > 0){
        add(digits, 0, "", "");
      }
      return ans;
    }
  
    void add(string digits, int callCnt, string comb, string newChar){
      comb += newChar;
      
      if (callCnt == digitLen){
        ans.push_back(comb);
        return;
      }
      
      switch(digits[callCnt]){
        case '2' : 
          add(digits, callCnt+1, comb, "a");
          add(digits, callCnt+1, comb, "b");
          add(digits, callCnt+1, comb, "c");
          break;
        case '3' :
          add(digits, callCnt+1, comb, "d");
          add(digits, callCnt+1, comb, "e");
          add(digits, callCnt+1, comb, "f");
          break;
        case '4' :
          add(digits, callCnt+1, comb, "g");
          add(digits, callCnt+1, comb, "h");
          add(digits, callCnt+1, comb, "i");
          break;
        case '5' :
          add(digits, callCnt+1, comb, "j");
          add(digits, callCnt+1, comb, "k");
          add(digits, callCnt+1, comb, "l");
          break;
        case '6' :
          add(digits, callCnt+1, comb, "m");
          add(digits, callCnt+1, comb, "n");
          add(digits, callCnt+1, comb, "o");
          break;
        case '7' :
          add(digits, callCnt+1, comb, "p");
          add(digits, callCnt+1, comb, "q");
          add(digits, callCnt+1, comb, "r");
          add(digits, callCnt+1, comb, "s");
          break;
        case '8' :
          add(digits, callCnt+1, comb, "t");
          add(digits, callCnt+1, comb, "u");
          add(digits, callCnt+1, comb, "v");
          break;
        case '9' :
          add(digits, callCnt+1, comb, "w");
          add(digits, callCnt+1, comb, "x");
          add(digits, callCnt+1, comb, "y");
          add(digits, callCnt+1, comb, "z");
          break;
      }
    }
};