//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  private:
   void dfs(int src,vector<int> &vis,stack<int> &st,vector<pair<int,int>> adj[]){
       vis[src]=1;
       for(auto x:adj[src]){
           auto p=x.first;
           dfs(p,vis,st,adj);
       }
       st.push(src);
   }
  public:
     vector<int> shortestPath(int n,int M, vector<vector<int>>& edges){
        // code here
        vector<pair<int,int>> adj[n];
        for(int i=0;i<M;i++){
            int u=edges[i][0];
            int v=edges[i][1];
            int w=edges[i][2];
            adj[u].push_back({v,w});
        }
        stack<int> st;
        vector<int> vis(n,0);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(i,vis,st,adj);
            }
        }
        vector<int> dis(n,1e9);
        dis[0]=0;
        while(!st.empty()){
            auto node=st.top();
            st.pop();
            for(auto it:adj[node]){
                int w=it.second;
                int u=it.first;
                dis[u]=min(dis[u],dis[node]+w);
    
                // if(dis[u]>dis[node]+w){
                //     dis[u]=dis[node]+w;
                // }
            }
        }
        for(int i=0;i<n;i++){
            if(dis[i]==1e9){
                dis[i]=-1;
            }
        }
        return dis;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends