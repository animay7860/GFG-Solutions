//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  private:
    void dfs(int row,int col,vector<vector<int>> &grid, vector<vector<int>> &vis,
    vector<pair<int,int>> &pp,int px,int py){
        int n=grid.size();
        int m=grid[0].size();
        pp.push_back({row-px,col-py});
        vis[row][col]=1;
        //  vector<int> x = { -1, -1, -1, 0, 0, 1, 1, 1 };
        //  vector<int> y = { -1, 0, 1, -1, 1, -1, 0, 1 };
         vector<int> x = {+1, -1, 0, 0};
         vector<int> y = {0, 0, +1, -1};
        for(int i=0;i<4;i++){
                int nrow=row+x[i];
                int ncol=col+y[i];
                if((nrow>=0 and nrow<n) and (ncol>=0 and ncol<m)
                and (grid[nrow][ncol]==1) and (!vis[nrow][ncol])){
                    dfs(nrow,ncol,grid,vis,pp,px,py);
              }
            
        }
    }     
  public:
    int countDistinctIslands(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        int cnt=0;
        set<vector<pair<int,int>>> st;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] and grid[i][j]==1){
                    vector<pair<int,int>> pp;
                    dfs(i,j,grid,vis,pp,i,j);
                    st.insert(pp);
                }
            }
        }
        return st.size();
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.countDistinctIslands(grid) << endl;
    }
}
// } Driver Code Ends