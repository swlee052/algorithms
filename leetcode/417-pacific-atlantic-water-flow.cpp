/*
Given an m x n matrix of non-negative integers representing the height of 
each unit cell in a continent, the "Pacific ocean" touches the left and top 
edges of the matrix and the "Atlantic ocean" touches the right and bottom 
edges.

Water can only flow in four directions (up, down, left, or right) from a cell 
to another one with height equal or lower.

Find the list of grid coordinates where water can flow to both the Pacific 
and Atlantic ocean.

Note:
The order of returned grid coordinates does not matter.
Both m and n are less than 150.
 

Example:
Given the following 5x5 matrix:

  Pacific ~   ~   ~   ~   ~ 
       ~  1   2   2   3  (5) *
       ~  3   2   3  (4) (4) *
       ~  2   4  (5)  3   1  *
       ~ (6) (7)  1   4   5  *
       ~ (5)  1   1   2   4  *
          *   *   *   *   * Atlantic

Return:
[[0, 4], [1, 3], [1, 4], [2, 2], [3, 0], [3, 1], [4, 0]] 
(positions with parentheses in above matrix).
*/


class Solution {
    vector<vector<bool>> at;
    vector<vector<bool>> pa;
    vector<vector<bool>> visit_a;
    vector<vector<bool>> visit_p;
    vector<vector<int>> ans;
    int numCol;
    int numRow;
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) { 
      if(matrix.empty()){
        return ans;
      }

      //initialization
      numRow = matrix.size();
      numCol = matrix[0].size();
      vector<bool> v(numCol, false);
      for(int i=0; i<numRow; i++){
        at.push_back(v);
        pa.push_back(v);
        visit_a.push_back(v);
        visit_p.push_back(v);
      }
      
      //dfs for pacific, call for every points on the margin
      for (int i=0; i<numRow; i++){ 
        dfs_p(i, 0, matrix);
        dfs_a(i, numCol-1, matrix);
      }
      for (int j=0; j<numCol; j++){ 
        dfs_p(0, j, matrix); 
        dfs_a(numRow-1, j, matrix);
      }
      
      //find indices that have access to both
      for (int i=0; i<numRow; i++){
        for(int j=0; j<numCol; j++){
          if (at[i][j] && pa[i][j]){
            vector<int> v{i, j};
            ans.push_back(v);
          }
        }
      }
      return ans;
    }
      
    void dfs_p(int row, int col, vector<vector<int>>& matrix){ 
      // exit if visited already. If not, mark as visited
      if (visit_p[row][col]){ 
        return;
      }
      visit_p[row][col] = true; // mark as visited
      
      //base cases
      if (row == 0 || col == 0){ 
          pa[row][col] = true; 
        }
      
      //recursive calls (have to traverse only right and downwards)
      if(row < numRow-1 && matrix[row][col] <= matrix[row+1][col]){
        pa[row+1][col] = pa[row][col];
        dfs_p(row+1, col, matrix);
      }
      if(row > 0 && matrix[row][col] <= matrix[row-1][col]){
        pa[row-1][col] = pa[row][col];
        dfs_p(row-1, col, matrix);
      }
      if(col < numCol-1 && matrix[row][col] <= matrix[row][col+1]){
        pa[row][col+1] = pa[row][col];
        dfs_p(row, col+1, matrix);
      }
      if(col > 0 && matrix[row][col] <= matrix[row][col-1]){
        pa[row][col-1] = pa[row][col];
        dfs_p(row, col-1, matrix);
      }
    }
  
    void dfs_a(int row, int col, vector<vector<int>>& matrix){ 
      // exit if visited already. If not, mark as visited
      if (visit_a[row][col]){ 
        return;
      }
      visit_a[row][col] = true; // mark as visited
      
      //base cases
      if (row == numRow-1 || col == numCol-1){ 
          at[row][col] = true; 
        }
      
      //recursive calls (have to traverse only right and downwards)
      if(row < numRow-1 && matrix[row][col] <= matrix[row+1][col]){
        at[row+1][col] = at[row][col];
        dfs_a(row+1, col, matrix);
      }
      if(row > 0 && matrix[row][col] <= matrix[row-1][col]){
        at[row-1][col] = at[row][col];
        dfs_a(row-1, col, matrix);
      }
      if(col < numCol-1 && matrix[row][col] <= matrix[row][col+1]){
        at[row][col+1] = at[row][col];
        dfs_a(row, col+1, matrix);
      }
      if(col > 0 && matrix[row][col] <= matrix[row][col-1]){
        at[row][col-1] = at[row][col];
        dfs_a(row, col-1, matrix);
      }
    }
};