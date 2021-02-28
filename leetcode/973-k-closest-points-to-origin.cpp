/*
We have a list of points on the plane.  Find the K closest points to the 
origin (0, 0).
(Here, the distance between two points on a plane is the Euclidean distance.)
You may return the answer in any order.  The answer is guaranteed to be unique 
(except for the order that it is in.)

Example 1:
Input: points = [[1,3],[-2,2]], K = 1
Output: [[-2,2]]

Explanation: 
The distance between (1, 3) and the origin is sqrt(10).
The distance between (-2, 2) and the origin is sqrt(8).
Since sqrt(8) < sqrt(10), (-2, 2) is closer to the origin.
We only want the closest K = 1 points from the origin, so the answer is just 
[[-2,2]].

Example 2:
Input: points = [[3,3],[5,-1],[-2,4]], K = 2
Output: [[3,3],[-2,4]]
(The answer [[-2,4],[3,3]] would also be accepted.)
 
Note:
1 <= K <= points.length <= 10000
-10000 < points[i][0] < 10000
-10000 < points[i][1] < 10000

*/

class Solution {
  vector<vector<int>> ans;
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
      find(0, points.size()-1, points, K);
      return ans;
    }
  
    void find(int start, int end, vector<vector<int>>& p, int K){
      if (K == 0){
        return;
      }
      
      //choose first element as pivot and compute distance
      int piv = p[start][0]*p[start][0] + p[start][1]*p[start][1];
      int bound = start;
      vector<int> tmp;
      
      //if smaller than pivot's distance, add to the bag
      for (int i = start+1; i<= end; i++){
        if(p[i][0]*p[i][0] + p[i][1]*p[i][1] <= piv){    
          bound++;
          tmp = p[bound]; // swap bound and i
          p[bound] = p[i];
          p[i] = tmp;
        }
      }
      tmp = p[bound]; // swap bound and start
      p[bound] = p[start];
      p[start] = tmp;
      
      //count elements smaller than pivot distance
      if(bound - start > K){ // throw away right part and search left
        find(start, bound-1, p, K);
      }
      else if (bound - start < K){ // add all of left and search right  
        for(int i = start; i<=bound; i++){
          ans.push_back(p[i]);
        }
        find(bound+1, end, p, K - (bound-start+1));
      }
      else { // add all of left and stop search
        for(int i = start; i<bound; i++){
          ans.push_back(p[i]);
        }
        return;
      }
    }
};