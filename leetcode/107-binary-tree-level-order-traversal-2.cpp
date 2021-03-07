/*
Given the root of a binary tree, return the bottom-up level order traversal 
of its nodes' values. (i.e., from left to right, level by level from leaf to 
root).

Example 1:
Input: root = [3,9,20,null,null,15,7]
Output: [[15,7],[9,20],[3]]

Example 2:
Input: root = [1]
Output: [[1]]

Example 3:
Input: root = []
Output: []
 
Constraints:
The number of nodes in the tree is in the range [0, 2000].
-1000 <= Node.val <= 1000
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), 
 *                                                          right(right) {}
 * };
 */

class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
      vector<vector<int>> ans;
      stack<vector<int>> ansStack;
      queue<TreeNode*> oldLevel;
      
      if (!root){
        return ans;
      }
      ansStack.push({root->val});
      oldLevel.push(root);
      
      do{
        queue<TreeNode*> newLevel;
        vector<int> newVec;
        while(!oldLevel.empty()){
          TreeNode* curr = oldLevel.front();
          oldLevel.pop();

          if(curr->left){
            newLevel.push(curr->left);
            newVec.push_back(curr->left->val);
          }
          if(curr->right){
            newLevel.push(curr->right);
            newVec.push_back(curr->right->val);
          }
        }
        oldLevel = newLevel;
        if(!newVec.empty()){
          ansStack.push(newVec);
        }
      }while(!oldLevel.empty());
        
        
      //generate answer using stack
      while(!ansStack.empty()){
        ans.push_back(ansStack.top());
        ansStack.pop();
      }
      return ans;
    }
};