/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
      vector<vector<int>> ans;
      stack<TreeNode*> oldLevel;
      bool leftToRight = false;
      
      if(!root){
        return ans;
      }
      ans.push_back({root->val});
      oldLevel.push(root);
      
      do{
        stack<TreeNode*> newLevel;
        vector<int> newVec;
        while(!oldLevel.empty()){
          TreeNode* old = oldLevel.top();
          oldLevel.pop();

          if(leftToRight){
            if(old->left){
              newVec.push_back(old->left->val);
              newLevel.push(old->left);
            }
            if(old->right){
              newVec.push_back(old->right->val);
              newLevel.push(old->right);
            }
          }
          else{
            if(old->right){
              newVec.push_back(old->right->val);
              newLevel.push(old->right);
            }
            if(old->left){
              newVec.push_back(old->left->val);
              newLevel.push(old->left);
            }
          }
        }
        if(!newVec.empty()){
          ans.push_back(newVec); 
        }
        oldLevel = newLevel;
        leftToRight = !leftToRight;
      }while(!oldLevel.empty());
      return ans;      
    }
};