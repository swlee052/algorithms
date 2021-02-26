/*
There are n cities. Some of them are connected, while some are not. If city a 
is connected directly with city b, and city b is connected directly with city 
c, then city a is connected indirectly with city c.

A province is a group of directly or indirectly connected cities and no other 
cities outside of the group.

You are given an n x n matrix isConnected where isConnected[i][j] = 1 if the 
ith city and the jth city are directly connected, and isConnected[i][j] = 0 
otherwise.

Return the total number of provinces.

Constraints:
1 <= n <= 200
n == isConnected.length
n == isConnected[i].length
isConnected[i][j] is 1 or 0.
isConnected[i][i] == 1
isConnected[i][j] == isConnected[j][i]
*/

class Solution {
    vector<int> pro;
    int numPro;
    int numCity;
  public:
    int findCircleNum(vector<vector<int>>& isConnected) {
      //initialize cities
      numCity = isConnected.size();
      for (int i=0; i<numCity; i++){ 
        pro.push_back(0);  
      }
      
      //dfs traverse
      numPro = 0;
      for(int i=0; i<numCity; i++){
        if (!pro[i]){
          numPro++;
          pro[i] = numPro; //assign province number
          dfs(i, isConnected); // dfs traverse to find all connected cities
        }
      }
      return numPro;
    }
  
    void dfs(int city, vector<vector<int>>& isConnected){
      for (int i=0; i<numCity; i++){
        if (!pro[i] && isConnected[i][city]){
          pro[i] = numPro;
          dfs(i, isConnected);
        }
      }
    }
};