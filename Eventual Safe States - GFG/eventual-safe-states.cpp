//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
    private:
    bool dfs(int src,vector<int> graph[],vector<int> &vis,vector<int> &path){
        vis[src]=1;
        path[src]=1;
        for(auto x:graph[src]){
            if(!vis[x]){
                if(dfs(x,graph,vis,path)) return true;
            }
            else if(path[x]==1){
                return true;
            }
        }
        path[src]=0;
        return false;
    }
  public:
    vector<int> eventualSafeNodes(int n, vector<int> graph[]) {
        // code here
        vector<int> ans;
        // int n=graph.size();   
        vector<int> vis(n,0);
        vector<int> path(n,0);
        // vector<int> chk(n,0);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(i,graph,vis,path);
            }
        }
        for(int i=0;i<n;i++){
            if(path[i]==0){
                ans.push_back(i);
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

        int V, E;
        cin >> V >> E;
        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        vector<int> safeNodes = obj.eventualSafeNodes(V, adj);
        for (auto i : safeNodes) {
            cout << i << " ";
        }
        cout << endl;
    }
}

// } Driver Code Ends