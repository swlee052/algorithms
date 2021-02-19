/*
Given an array of integers arr of even length, return true if and only if it 
is possible to reorder it such that arr[2 * i + 1] = 2 * arr[2 * i] for every 
0 <= i < len(arr) / 2.

Example 1:
Input: arr = [3,1,3,6]
Output: false

Example 2:
Input: arr = [2,1,2,6]
Output: false

Example 3:
Input: arr = [4,-2,2,-4]
Output: true
Explanation: We can take two groups, [-2,-4] and [2,4] to form [-2,-4,2,4] or 
[2,4,-2,-4].

Example 4:
Input: arr = [1,2,4,16,8,4]
Output: false
 

Constraints:
0 <= arr.length <= 3 * 104
arr.length is even.
-105 <= arr[i] <= 105
*/

class Solution {
public:
    bool canReorderDoubled(vector<int>& arr) {
      //separate the array to negative, positive and zeroes
      vector<int> neg, pos;
      int size = arr.size();
      int zeroCnt = 0;
      for (int i=0; i<size; i++){
        if (arr[i] < 0){
          neg.push_back(arr[i]);
        }
        else if (arr[i] == 0){
          zeroCnt++;
        }
        else{
          pos.push_back(arr[i]);
        }
      }
      
      //return false if there are odd number of zeroes
      if(zeroCnt%2 == 1){
        return false;
      }
      
      //verify neg and pos and return
      return verify(neg) && verify(pos);
    }
  
  bool verify(vector<int>& arr) { 
    //exception handling
    int size = arr.size();
    if (size==0){
      return true;
    }
    else if (size%2==1){
      return false;
    }
    
    //sort array by absolute values
    if (arr[0] < 0){
      sort(arr.begin(), arr.end(), greater<int>());
    }
    else {
      sort(arr.begin(), arr.end());
    }
    
    //verify by placing zeroes for used elements
    int piv = 0; //pivot index
    int i = 1; //comparing index
    int zeroCnt = 0;
    while(i<size){
      if (arr[piv] == 0){ // already paired up
        piv++;
      }
      else if (arr[piv]*2==arr[i]){ // use to pair up
        arr[i] = 0;
        piv++;
        zeroCnt++;
        i++;
      }
      else {
        i++;
      }
    }
    return zeroCnt == size/2; // number of pairs should be half
  }
};
