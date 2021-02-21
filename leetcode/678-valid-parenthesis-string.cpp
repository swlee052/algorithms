/*
Given a string s containing only three types of characters: '(', ')' and '*', 
return true if s is valid.

The following rules define a valid string:
Any left parenthesis '(' must have a corresponding right parenthesis ')'.
Any right parenthesis ')' must have a corresponding left parenthesis '('.
Left parenthesis '(' must go before the corresponding right parenthesis ')'.
'*' could be treated as a single right parenthesis ')' or a single left 
parenthesis '(' or an empty string "".
*/

class Solution {
public:
    bool checkValidString(string s) {
      short int size = s.length();
      vector<short int> star;
      vector<short int> left;
      
      // process all right parentheses
      for (short int i=0; i<size; i++){
        char c = s.at(i);
        if (c == '('){
          left.push_back(i);
        }
        else if (c == ')'){
          if (left.size() != 0){ //erase one '('
            left.pop_back();
          }
          else if (star.size()!=0){ //erase one '*'
            star.pop_back();
          }
          else {
            return false;
          }
        }
        else if (c == '*'){
          star.push_back(i);
        }
        else { // char other than '(', ')', or '*'
          return false;
        }
      }
      
      //process all left parentheses
      while (left.size() != 0){
        if (star.size() == 0){ // no more stars left
          return false;
        }
        else if (star.back() > left.back()){ // erase one star and one left p
          star.pop_back();
          left.pop_back();
        }
        else { // no more stars behind the rightmost left parenthesis
          return false;
        }
      }

      return true;
    }
};