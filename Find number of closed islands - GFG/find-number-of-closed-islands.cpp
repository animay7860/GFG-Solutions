//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
    public:
    int closedIslands(vector<vector<int>>& grid, int n, int m) {
        // int n=grid.size();
        // int m=grid[0].size();
        queue<pair<int,int>> q;
        vector<vector<int>> vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0 or j==0 or i==n-1 or j==m-1){
                    if(grid[i][j]==1 and !vis[i][j]){
                        vis[i][j]=1;
                       q.push({i,j});
                    }
                 
                }
            }
        }
        while(!q.empty()){
            // auto [r,c]=q.front();
            auto r=q.front().first;
            auto c=q.front().second;
            q.pop();
        int x[]={1,-1,0,0};
        int y[]={0,0,1,-1};
        for(int i=0;i<4;i++){
            int nrow=x[i]+r;
            int ncol=y[i]+c;
            if(nrow>=0 and ncol>=0 and ncol<m and nrow<n 
            and grid[nrow][ncol]==1 and !vis[nrow][ncol]){
                vis[nrow][ncol]=1;
                q.push({nrow,ncol});
            }
        }
        }
        int island=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1 and !vis[i][j]){
                    island++;
                    q.push({i,j});
                    while(!q.empty()){
                    // auto [r,c]=q.front();
                    auto r=q.front().first;
               auto c=q.front().second;
                     q.pop();
                   int x[]={1,-1,0,0};
                 int y[]={0,0,1,-1};
              for(int i=0;i<4;i++){
                int nrow=x[i]+r;
                int ncol=y[i]+c;
               if(nrow>=0 and ncol>=0 and ncol<m and nrow<n 
                and grid[nrow][ncol]==1 and !vis[nrow][ncol]){
                vis[nrow][ncol]=1;
                q.push({nrow,ncol});
            }
                    }
                }
            }
        }
        }
return island;
    }
};

//{ Driver Code Starts.
int main() {
	int t;
	cin>>t;
	while(t--)
	{
        int N, M;
        cin >> N >> M;
        vector<vector<int>>matrix(N, vector<int>(M, 0));
        for(int i=0; i<N; i++)
            for(int j=0; j<M; j++)
                cin >> matrix[i][j];
                
        Solution obj;
        int ans = obj.closedIslands(matrix, N, M);
        cout << ans << "\n";
    }
	
	return 0;
	
}


// } Driver Code Ends