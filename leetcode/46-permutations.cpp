/*
Given an array nums of distinct integers, return all the possible 
permutations. You can return the answer in any order.

Example 1:
Input: nums = [1,2,3]
Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]

Example 2:
Input: nums = [0,1]
Output: [[0,1],[1,0]]

Example 3:
Input: nums = [1]
Output: [[1]]
 
Constraints:
1 <= nums.length <= 6
-10 <= nums[i] <= 10
All the integers of nums are unique.
*/

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
      vector<vector<int>> ans;
      vector<int> v;
      vector<bool> used(nums.size(), false);
      if(nums.empty()){
        return ans;
      }
  
      dfs(nums, ans, v, used);
      return ans;
    }
  
    void dfs(vector<int>& nums, vector<vector<int>>& ans, vector<int> v, 
                    vector<bool> used){
      int sz = nums.size();
      
      if(v.size() == sz){
        ans.push_back(v);
        return;
      }
      for(int i=0; i<sz; i++){
        vector<int> vecCopy = v;
        vector<bool> usedCopy = used;
        if(!used[i]){
          vecCopy.push_back(nums[i]);
          usedCopy[i] = true;
          dfs(nums, ans, vecCopy, usedCopy);
        }
      }
    }
};