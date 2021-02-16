/*
https://leetcode.com/problems/pyramid-transition-matrix/
756. Pyramid Transition Matrix

We are stacking blocks to form a pyramid. Each block has a color which is a 
one letter string. We are allowed to place any color block C on top of two 
adjacent blocks of colors A and B, if and only if ABC is an allowed triple.
We start with a bottom row of bottom, represented as a single string. We also
start with a list of allowed triples allowed. Each allowed triple is 
represented as a string of length 3. Return true if we can build the pyramid 
all the way to the top, otherwise false.

Example 1:

Input: bottom = "BCD", allowed = ["BCG", "CDE", "GEA", "FFF"]
Output: true
Explanation:
We can stack the pyramid like this:
    A
   / \
  G   E
 / \ / \
B   C   D

We are allowed to place G on top of B and C because BCG is an allowed triple.  
Similarly, we can place E on top of C and D, then A on top of G and E.
 

Example 2:

Input: bottom = "AABA", allowed = ["AAA", "AAB", "ABA", "ABB", "BAC"]
Output: false
Explanation:
We can't stack the pyramid to the top.
Note that there could be allowed triples (A, B, C) and (A, B, D) with C != D.
 

Constraints:

bottom will be a string with length in range [2, 8].
allowed will have length in range [0, 200].
Letters in all strings will be chosen from the set 
{'A', 'B', 'C', 'D', 'E', 'F', 'G'}.
*/

#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    bool pyramidTransition(string bottom, vector<string>& allowed) {
      vector<vector<string>> possibleChar; 
      vector<string> newBottom;
      bool retVal = false;
      
      // compute all possible characters for each position (next level)
      int size = allowed.size();
      string currSubStr;
      int newBottomSize = bottom.length() -1;
      for (int j=0; j<newBottomSize; j++){
        currSubStr = bottom.substr(j, 2);
        for (int i=0; i<size; i++){
          if (allowed[i].substr(0,2) == currSubStr) {
            possibleChar[j].push_back(allowed[i].substr(2,1));
          }
        }
      }
      
      /*some function that does this
      [[a, b], [a,b,c], [a]] -> [aaa, aba, aca, baa, bba, bca]
      */
      
      // combine all possibile newBottom's boolean value
      int newBottomSize = newBottom.size();
      for (int i=0; i<newBottomSize; i++){
        retVal = retVal || pyramidTransition(newBottom[i], allowed);
      }
      return retVal;
    }
};