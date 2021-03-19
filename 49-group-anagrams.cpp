/*
Given an array of strings strs, group the anagrams together. You can return 
the answer in any order. An Anagram is a word or phrase formed by rearranging 
the letters of a different word or phrase, typically using all the original 
letters exactly once.

Example 1:
Input: strs = ["eat","tea","tan","ate","nat","bat"]
Output: [["bat"],["nat","tan"],["ate","eat","tea"]]

Example 2:
Input: strs = [""]
Output: [[""]]

Example 3:
Input: strs = ["a"]
Output: [["a"]]
 
Constraints:
1 <= strs.length <= 104
0 <= strs[i].length <= 100
strs[i] consists of lower-case English letters.
*/

/*
https://stackoverflow.com/questions/3578083/what-is-the-best-way-to-use-a-hashmap-in-c
my solution : O(n) insertion and fetch
map: redblack tree, O(logn) insert and find
umap: hashtable, O(1) ~ O(N) find, O(1) insert
*/

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
      vector<vector<string>> ans;
      
      //push initial element, initialize variables
      unordered_map<string, vector<string>> map;
      int sz = strs.size();
      string key;
      
      //store in map
      for(auto& s : strs){
        key = getKey(s);
        map[key].push_back(s);
      }
    
      //copy buckets in map
      for(auto& p : map){
        ans.push_back(move(p.second));
      }
      return ans;
    }
  
    //returns key for the map (hashtable)
    string getKey(string s){ 
      string key;
      short int count[26] = {0};
      for(char c : s){
        count[c-'a'] += 1;
      }
      
      for(int i=0; i<25; i++){
        key += to_string(count[i]);
        key += "#";
      }
      key += to_string(count[25]);
      return key;
    }
};