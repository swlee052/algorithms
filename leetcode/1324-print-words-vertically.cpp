/*
Given a string s. Return all the words vertically in the same order in which 
they appear in s. Words are returned as a list of strings, complete with 
spaces when is necessary. (Trailing spaces are not allowed). Each word would 
be put on only one column and that in one column there will be only one word.


Example 1:
Input: s = "HOW ARE YOU"
Output: ["HAY","ORO","WEU"]
Explanation: Each word is printed vertically. 
 "HAY"
 "ORO"
 "WEU"

Example 2:
Input: s = "TO BE OR NOT TO BE"
Output: ["TBONTB","OEROOE","   T"]
Explanation: Trailing spaces is not allowed. 
"TBONTB"
"OEROOE"
"   T"

Example 3:
Input: s = "CONTEST IS COMING"
Output: ["CIC","OSO","N M","T I","E N","S G","T"]
 

Constraints:
1 <= s.length <= 200
s contains only upper case English letters.
It's guaranteed that there is only one space between 2 words.
*/

class Solution {
public:
    vector<string> printVertically(string s) {
      vector<string> token;
      vector<string> retVal;
      int start = 0;
      int len = s.length();
      int maxTokenLen = 0;

      //tokenize string
      for (int i=0; i<len; i++){
        if (s.at(i) == ' ') {
          if (i-start > maxTokenLen){
            maxTokenLen = i-start;
          }
          token.push_back(s.substr(start, i-start));
          start = i+1;
        }
        else if (i == len-1){
          if (i+1-start > maxTokenLen){
            maxTokenLen = i+1-start;
          }
          token.push_back(s.substr(start, i+1-start));
        }
      }
      
      //generate and add vertical strings to retVal vector
      int ix = 0;
      string vert;
      for (int i=0; i<maxTokenLen; i++){
        vert = "";
        for (string t : token){
          if (t.size() <= ix){
            vert += " ";
          }
          else {
            vert += t.at(ix);   
          }
        }
        
        //delete trailing spaces for each vertical string
        while(vert.back() ==  ' '){
          vert.pop_back();
        }
        retVal.push_back(vert);
        ix++;
      }
      return retVal;
    }
};