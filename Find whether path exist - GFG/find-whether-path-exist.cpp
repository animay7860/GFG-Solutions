//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    //Function to find whether a path exists from the source to destination.
    bool is_Possible(vector<vector<int>>& grid) 
    {
        //code here
        int n=grid.size();
        int m=grid[0].size();
        int dx=-1,dy=-1;
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1) q.push({i,j});
                else if(grid[i][j]==2) dx=i,dy=j;
            }
        }
        vector<vector<int>> vis(n,vector<int>(m,0));
        
        while(!q.empty()){
            auto r=q.front().first;
            auto c=q.front().second;
            vis[r][c]=1;
            q.pop();
            if(r==dx and c==dy) return 1;
            int a[]={1,-1,0,0};
            int b[]={0,0,1,-1};
            for(int i=0;i<4;i++){
                int nrow=a[i]+r;
                int ncol=b[i]+c;
                if(ncol>=0 and nrow>=0 and ncol<m and nrow<n and grid[nrow][ncol]>=2 and !vis[nrow][ncol]){
                    q.push({nrow,ncol});
                    vis[nrow][ncol]=1;
                }
            }
        }
        return 0;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>grid(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		bool ans = obj.is_Possible(grid);
		cout << ((ans) ? "1\n" : "0\n");
	}
	return 0;
}
// } Driver Code Ends