//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        // code here
        vector<vector<char>> ans;
        vector<vector<int>> vis(n,vector<int>(m,0));
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0 or i==n-1 or j==m-1 or j==0){
                    if(mat[i][j]=='O'){
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
            vector<int> x = {+1, -1, 0, 0};
            vector<int> y = {0, 0, +1, -1};
            for(int i=0;i<4;i++){
                int nrow=r+x[i];
                int ncol=c+y[i];
               if(nrow>0 and ncol>0 and ncol<m and nrow<n and !vis[nrow][ncol] and mat[nrow][ncol]=='O'){
                   vis[nrow][ncol]=1;
                   q.push({nrow,ncol});
               }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] and mat[i][j]=='O'){
                    mat[i][j]='X';
                }
            }
        }
        ans=mat;
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<char>> mat(n, vector<char>(m, '.'));
        for(int i = 0;i < n;i++)
            for(int j=0; j<m; j++)
                cin>>mat[i][j];
        
        Solution ob;
        vector<vector<char>> ans = ob.fill(n, m, mat);
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                cout<<ans[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends