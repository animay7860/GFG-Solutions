//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  private:
  bool dfs(vector<int> adj[],int src,vector<int> &vis,vector<int> &path)
  {
      vis[src]=1;
      path[src]=1;
      for(auto x:adj[src]){
          if(!vis[x]){
              if(dfs(adj,x,vis,path)){
                  return true;
              }
          }
          else if(path[x]==1){
              return true;
          }
      }
      path[src]=0;
      return false;
  }
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int v, vector<int> adj[]) {
        // code here
        vector<int> vis(v,0);
        vector<int> path(v,0);
        for(int i=0;i<v;i++){
            if(!vis[i]){
                if(dfs(adj,i,vis,path)) return true;
            }
        }
        return false;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends