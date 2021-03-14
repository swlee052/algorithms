/*
Given an integer array nums of unique elements, return all possible subsets 
(the power set). The solution set must not contain duplicate subsets. Return 
the solution in any order.


Example 1:
Input: nums = [1,2,3]
Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]

Example 2:
Input: nums = [0]
Output: [[],[0]]
 
Constraints:
1 <= nums.length <= 10
-10 <= nums[i] <= 10
All the numbers of nums are unique.
*/


class Solution {
public:
  vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> ans;
    if(nums.empty()){
      return ans;
    }
    
    //add [] and [0] to the ans
    vector<int> v;
    ans.push_back(v);
    v.push_back(nums[0]);
    ans.push_back(v);
    
    //recursion
    add(ans, nums, 1);
    return ans;
  }

  void add(vector<vector<int>>& ans, vector<int>& nums, int idx){
    if(idx >= nums.size()){
      return;
    }
    
    //duplicate ans and add the new element then append to the old ans 
    int sz = ans.size();
    for(int i=0; i<sz; i++){
      ans.push_back(ans[i]);
    }
    for(int i=sz; i<2*sz; i++){
      ans[i].push_back(nums[idx]);
    }
    
    add(ans, nums, idx+1);
  }
};