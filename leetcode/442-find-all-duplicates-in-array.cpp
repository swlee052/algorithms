/*
Given an array of integers, 1 ≤ a[i] ≤ n (n = size of array), some elements appear twice and others appear once.

Find all the elements that appear twice in this array.

Could you do it without extra space and in O(n) runtime?

Example:
Input:
[4,3,2,7,8,2,3,1]

Output:
[2,3]
*/

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
      int size = nums.size();
      int ix = 0;
      vector<int> ans;
      for (int i=0; i<size; i++){
        if (nums[i] < 0){
          ix = -nums[i] - 1;
        }
        else {
          ix = nums[i] - 1; 
        }
       
        if (nums[ix] < 0){
          ans.push_back(ix + 1);
        }
        else {
          nums[ix] = -nums[ix];
        }
         cout << i << " " << ix << " " << nums[ix] << endl;
      }
      return ans;
    }
};