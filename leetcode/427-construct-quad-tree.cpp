/*
Given a n * n matrix grid of 0's and 1's only. We want to represent the grid 
with a Quad-Tree. Return the root of the Quad-Tree representing the grid.
Notice that you can assign the value of a node to True or False when isLeaf 
is False, and both are accepted in the answer.

A Quad-Tree is a tree data structure in which each internal node has exactly 
four children. Besides, each node has two attributes:

val: True if the node represents a grid of 1's or False if the node 
represents a grid of 0's. 
isLeaf: True if the node is leaf node on the tree or False if the node has
the four children.

class Node {
    public boolean val;
    public boolean isLeaf;
    public Node topLeft;
    public Node topRight;
    public Node bottomLeft;
    public Node bottomRight;
}

We can construct a Quad-Tree from a two-dimensional area using the following 
steps:

If the current grid has the same value (i.e all 1's or all 0's) set isLeaf 
True and set val to the value of the grid and set the four children to Null 
and stop.
If the current grid has different values, set isLeaf to False and set val to 
any value and divide the current grid into four sub-grids as shown in the 
photo. Recurse for each of the children with the proper sub-grid.

If you want to know more about the Quad-Tree, you can refer to the wiki.

Quad-Tree format:

The output represents the serialized format of a Quad-Tree using level order 
traversal, where null signifies a path terminator where no node exists below.

It is very similar to the serialization of the binary tree. The only 
difference is that the node is represented as a list [isLeaf, val].

If the value of isLeaf or val is True we represent it as 1 in the list 
[isLeaf, val] and if the value of isLeaf or val is False we represent it as 0.

Example 1:
Input: grid = [[0,1],[1,0]]
Output: [[0,1],[1,0],[1,1],[1,1],[1,0]]
Explanation: The explanation of this example is shown below:
Notice that 0 represnts False and 1 represents True in the photo representing 
the Quad-Tree.

Example 2:
Input: grid = [[1,1,1,1,0,0,0,0],[1,1,1,1,0,0,0,0],[1,1,1,1,1,1,1,1],
[1,1,1,1,1,1,1,1],[1,1,1,1,0,0,0,0],[1,1,1,1,0,0,0,0],[1,1,1,1,0,0,0,0],
[1,1,1,1,0,0,0,0]]
Output: [[0,1],[1,1],[0,1],[1,1],[1,0],null,null,null,null,[1,0],[1,0],[1,1],
[1,1]]
Explanation: All values in the grid are not the same. We divide the grid into 
four sub-grids. The topLeft, bottomLeft and bottomRight each has the same 
value. The topRight have different values so we divide it into 4 sub-grids 
where each has the same value. Explanation is shown in the photo below:

Example 3:

Input: grid = [[1,1],[1,1]]
Output: [[1,1]]
Example 4:

Input: grid = [[0]]
Output: [[1,0]]
Example 5:

Input: grid = [[1,1,0,0],[1,1,0,0],[0,0,1,1],[0,0,1,1]]
Output: [[0,1],[1,1],[1,0],[1,0],[1,1]]
 

Constraints:
n == grid.length == grid[i].length
n == 2^x where 0 <= x <= 6
*/



/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
public:
    Node* construct(vector<vector<int>>& grid) {
      Node *root = new Node;
      int size = grid.size();
      int sum = 0;
      
      //determine isLeaf and val
      for (int i=0; i<size; i++){
        for (int j=0; j<size; j++){
          sum += grid[i][j];
        }  
      }
      
      if (sum == pow(size,2)){
        root->isLeaf = true;
        root->val = true;
        return root;
      }
      else if (sum == 0){
        root->isLeaf = true;
        root->val = false;
        return root;
      }
      else {
        root->isLeaf = false;
        root->val = true;
      }
      
      //create subgrids
      vector<vector<int>> tl;
      vector<vector<int>> tr;
      vector<vector<int>> bl;
      vector<vector<int>> br;

      for(int row=0; row<size/2; row++){
        vector<int>::const_iterator first = grid[row].begin();
        vector<int>::const_iterator last = grid[row].begin() + size/2;
        vector<int> newRow(first, last);
        tl.push_back(newRow);
      }
      
      for(int row=0; row<size/2; row++){
        vector<int>::const_iterator first = grid[row].begin() + size/2;
        vector<int>::const_iterator last = grid[row].begin() + size;
        vector<int> newRow(first, last);
        tr.push_back(newRow);
      }
      
      for(int row=size/2; row<size; row++){
        vector<int>::const_iterator first = grid[row].begin();
        vector<int>::const_iterator last = grid[row].begin() + size/2;
        vector<int> newRow(first, last);
        bl.push_back(newRow);
      }
      
      for(int row=size/2; row<size; row++){
        vector<int>::const_iterator first = grid[row].begin() + size/2;
        vector<int>::const_iterator last = grid[row].begin() + size;
        vector<int> newRow(first, last);
        br.push_back(newRow);
      }
      
      //assign subgrids to root
      root -> topLeft = construct(tl);
      root -> topRight = construct(tr);
      root -> bottomLeft = construct(bl);
      root -> bottomRight = construct(br);
      return root;
    }
};