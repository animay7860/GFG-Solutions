//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find distance of nearest 1 in the grid for each cell.
	vector<vector<int>>nearest(vector<vector<int>>g)
	{
	    // Code here
	   
	    int n=g.size();
	    int m=g[0].size();
	    vector<vector<int>> dist(n,vector<int>(m,0));
	    vector<vector<int>> vis(n,vector<int>(m,0));
	    queue<pair<pair<int,int>,int>> q;
	    for(int i=0;i<n;i++){
	        for(int j=0;j<m;j++){
	            if(g[i][j]==1){
	                q.push({{i,j},0}); 
	                vis[i][j]=1;
	            }
	        }
	    }
	    while(!q.empty()){
	        auto x=q.front().first.first;
	        auto y=q.front().first.second;
	        auto step=q.front().second;
	        dist[x][y]=step;
	        q.pop();
	        vector<int> xx = {+1, -1, 0, 0};
            vector<int> yy = {0, 0, +1, -1};
            for(int i=0;i<4;i++){
                int nrow=x+xx[i];
                int ncol=y+yy[i];
                if(nrow>=0 and ncol>=0 and ncol<m and nrow<n and !vis[nrow][ncol] and g[nrow][ncol]==0){
                    vis[nrow][ncol]=1;
                    q.push({{nrow,ncol},step+1});
                }
            }
	        
	    }
	    return dist;
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
		vector<vector<int>> ans = obj.nearest(grid);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends