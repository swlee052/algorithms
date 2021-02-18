/*
Given an integer array nums where every element appears three times except 
for one, which appears exactly once. Find the single element and return it.

 

Example 1:

Input: nums = [2,2,3,2]
Output: 3
Example 2:

Input: nums = [0,1,0,1,0,1,99]
Output: 99
 

Constraints:
1 <= nums.length <= 3 * 104
-231 <= nums[i] <= 231 - 1
Each element in nums appears exactly three times except for one element which 
appears once.
 
Follow up: Your algorithm should have a linear runtime complexity. Could you 
implement it without using extra memory?
*/

class Solution {
public:
    int singleNumber(vector<int>& nums) {
      int size = nums.size();
      int bit[32] = {0};
      bool numBit;
      int retVal = 0;
      int num;
      
      for (int i=0; i<size; i++){
        num = nums[i];
        for(int j=0; j<32; j++){
          numBit = num & 1;
          if (numBit) { // 0 -> 1 -> -1 -> 0
            if (bit[j] == 1){
              bit[j] = -1;
            }
            else if (bit[j] == 0){
              bit[j] = 1;
            }
            else {
              bit[j] = 0;
            }
          }
          num = num >> 1;
        }
      }
      
      
      // construct answer (bits array -> integer)
      for(int i=0; i<32; i++){
        retVal += bit[i]<<i;
      }
      return retVal;
    }
};