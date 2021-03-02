/*
Given an array of integers nums containing n + 1 integers where each integer 
is in the range [1, n] inclusive. There is only one repeated number in nums, 
return this repeated number.

 

Example 1:
Input: nums = [1,3,4,2,2]
Output: 2

Example 2:
Input: nums = [3,1,3,4,2]
Output: 3

Example 3:
Input: nums = [1,1]
Output: 1

Example 4:
Input: nums = [1,1,2]
Output: 1
 

Constraints:
2 <= n <= 3 * 104
nums.length == n + 1
1 <= nums[i] <= n
All the integers in nums appear only once except for precisely one integer 
which appears two or more times.
 

Follow up:
How can we prove that at least one duplicate number must exist in nums?
Can you solve the problem without modifying the array nums?
Can you solve the problem using only constant, O(1) extra space?
Can you solve the problem with runtime complexity less than O(n2)?
*/


class Solution {
    int ans;
  public: 
    int findDuplicate(vector<int>& nums) {
      first(nums);
      return ans;
    }
    
    // binary search using the pigeon hole concept, O(nlogn), follow up 1
    void first(vector<int>& nums){ 
      int left = 1;
      int right = nums.size()-1;
      int cnt = 0;
      int mid;
      
      while (left < right){
        mid = left + (right - left)/2;
        cnt = 0;
        for (int n : nums){
          if(n <= mid){
            cnt++;
          }
        }
        
        if (cnt <= mid){
          left = mid+1;
        }
        else {
          right = mid;
        }
      }
      ans = left;
    }
  

    // satisfies follow up 2 and 3
    void second(vector<int>& nums){ 
      for(int n : nums){
        if(nums[abs(n)-1] < 0){
          ans = abs(n);
          return;
        }
        nums[abs(n)-1] = -nums[abs(n)-1];
      }
    }
};