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
        if (bottom.length() == 1) {
            return true;
        }

        vector<vector<string>> combList;
        string comb;
        for(int j=0; j<bottom.size()-1; j++){
            for(int i=0; i<allowed.size(); i++){
            if (bottom[j].substr(0, 2) == allowed[i].substr(0, 2))
                combList[j].push_back(bottom[j][2]);
            }
        }

        // No valid combination -> return false
        for(int j=0; j<bottom.size()-1; j++){ 
            if(combList[j].size() == 0) {
                return false;
            }
        }

        bool retVal;
        string comb = "";
        for(int j=0; j<bottom.size()-1; j++){
            
            for (int i=0; i<combList.size(); i++){
                retVal = retVal || pyramidTransition(combList[i], 
                                                        vector<string>& allowed);
            }
        }
        return retVal;
    }
};