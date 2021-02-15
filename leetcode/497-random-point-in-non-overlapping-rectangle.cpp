/*
https://leetcode.com/problems/random-point-in-non-overlapping-rectangles/
497. Random Point in Non-overlapping Rectangles

Given a list of non-overlapping axis-aligned rectangles rects, write a 
function pick which randomly and uniformily picks an integer point in the 
space covered by the rectangles.

Note:
An integer point is a point that has integer coordinates. 
A point on the perimeter of a rectangle is included in the space covered by the rectangles. 
ith rectangle = rects[i] = [x1,y1,x2,y2], where [x1, y1] are the integer coordinates of the bottom-left corner, and [x2, y2] are the integer coordinates of the top-right corner.
length and width of each rectangle does not exceed 2000.
1 <= rects.length <= 100
pick return a point as an array of integer coordinates [p_x, p_y]
pick is called at most 10000 times.

Example 1:
Input: 
["Solution","pick","pick","pick"]
[[[[1,1,5,5]]],[],[],[]]
Output: 
[null,[4,1],[4,1],[3,3]]

Example 2:
Input: 
["Solution","pick","pick","pick","pick","pick"]
[[[[-2,-2,-1,-1],[1,0,3,0]]],[],[],[],[],[]]
Output: 
[null,[-1,-2],[2,0],[-2,-1],[3,0],[-2,-2]]

Explanation of Input Syntax:
The input is two lists: the subroutines called and their arguments. 
Solution's constructor has one argument, the array of rectangles rects. 
pick has no arguments. Arguments are always wrapped with a list, even if 
there aren't any.
*/

 

class Solution {
  vector<int> area;
  int chosenWidth;
  int chosenHeight;
  int x_shift;
  int y_shift;
  
  public:
    Solution(vector<vector<int>>& rects) {
      int width = 0;
      int height = 0;
      int areaSum = 0;
      
      //compute area
      for (int i=0; i<rects.size(); i++){
        width = rects[i][2] - rects[i][0];
        height = rects[i][3] - rects[i][1];
        area.push_back(width * height);
        areaSum += width * height;
      }

      double randNum = ((double) (rand()/RAND_MAX)) * areaSum;
      double cnt = 0;
      
      //choose rectangle
      for (int i=0; i<area.size(); i++){
        cnt += area[i];
        if (cnt >= randNum) {
          x_shift = rects[i][0];
          y_shift = rects[i][1];
          chosenWidth = rects[i][2] - rects[i][0];
          chosenHeight = rects[i][3] - rects[i][1];
          break;
        }
      }
      
    }
    
    vector<int> pick() {
      int rand_x = floor(((double) rand()/RAND_MAX) * chosenWidth) + x_shift;
      int rand_y = floor(((double) rand()/RAND_MAX) * chosenHeight) + y_shift;
      vector<int> ans;
      ans.push_back(rand_x);
      ans.push_back(rand_y);
      return ans;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(rects);
 * vector<int> param_1 = obj->pick();
 */