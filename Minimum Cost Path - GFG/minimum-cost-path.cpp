//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    public:
    //Function to return the minimum cost to react at bottom
	//right cell from top left cell.
    int minimumCostPath(vector<vector<int>>& grid) 
    {
        // Code here
        int n=grid.size();
        int m=grid[0].size();
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>
        ,greater<pair<int,pair<int,int>>>>pq;
        vector<vector<int>> dist(n,vector<int>(m,1e9));
        dist[0][0]=grid[0][0];
        pq.push({dist[0][0],{0,0}});
        while(!pq.empty()){
            auto dis=pq.top().first;
            auto r=pq.top().second.first;
            auto c=pq.top().second.second;
            pq.pop();
            int a[]={1,-1,0,0};
            int b[]={0,0,1,-1};
            if(r==n-1 and c==m-1) return dis;
            for(int i=0;i<4;i++){
                int nrow=r+a[i];
                int ncol=c+b[i];
                if(nrow>=0 and nrow<n and ncol>=0 and ncol<m){
                    if(dist[nrow][ncol]>dis+grid[nrow][ncol]){
                        dist[nrow][ncol]=dis+grid[nrow][ncol];
                        pq.push({dist[nrow][ncol],{nrow,ncol}});
                    }
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
		int ans = obj.minimumCostPath(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends