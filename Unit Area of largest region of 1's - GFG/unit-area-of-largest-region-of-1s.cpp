//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    private:
    int bfs(int row,int col,vector<vector<int>> &g,vector<vector<int>> &vis){
        int n=g.size();
        int m=g[0].size();
        vis[row][col]=1;
        int count=1;
        queue<pair<int,int>> q;
        q.push({row,col});
        while(!q.empty()){
            // auto [r,c]=q.front();
            auto r=q.front().first;
            auto c=q.front().second;
            q.pop();
            int x[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
            int y[] = { -1, 0, 1, -1, 1, -1, 0, 1 };
            for(int i=0;i<8;i++){
             int nrow=r+x[i];
             int ncol=c+y[i];
             if(nrow>=0 and ncol>=0 and nrow<n and ncol<m and !vis[nrow][ncol] and g[nrow][ncol]==1){
                 vis[nrow][ncol]=1;
                 q.push({nrow,ncol});
                 count++;
             }
            }
        }
        return count;
    }    
    public:
    //Function to find unit area of the largest region of 1s.
    int findMaxArea(vector<vector<int>>& g) {
        // Code here
        int n=g.size();
        int m=g[0].size();
        int ans=0;
        vector<vector<int>> vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
         for(int j=0;j<m;j++){
             if(!vis[i][j] and g[i][j]==1){
                ans=max(ans,bfs(i,j,g,vis));
             }
         }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.findMaxArea(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends