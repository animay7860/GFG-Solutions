//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int numberOfEnclaves(vector<vector<int>> &g) {
        // Code here
        int n=g.size();
        int m=g[0].size();
        queue<pair<int,int>> q;
        vector<vector<int>> vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0 or i==n-1 or j==0 or j==m-1){
                if(g[i][j]==1){
                  q.push({i,j});
                  vis[i][j]=1;
                }
            }
        }
        }
        while(!q.empty()){
            // auto [r,c]=q.front();
            auto r=q.front().first;
            auto c=q.front().second;
            q.pop();
            vector<int> x = {+1, -1, 0, 0};
            vector<int> y = {0, 0, +1, -1};
            for(int i=0;i<4;i++){
                int nrow=r+x[i];
                int ncol=c+y[i];
                if(nrow>0 and nrow<n and ncol>0 and ncol<m and !vis[nrow][ncol] and g[nrow][ncol]==1){
                    q.push({nrow,ncol});
                    vis[nrow][ncol]=1;
                }
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] and g[i][j]==1){
                    ans++;
                }
            }
        }
        return ans;
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
        cout << obj.numberOfEnclaves(grid) << endl;
    }
}
// } Driver Code Ends