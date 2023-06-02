//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  private:
    bool bfs(vector<int> adj[],int v, int vis[],int src){
        queue<pair<int ,int>> q;
        q.push({src,-1});
        vis[src]=1;
        while(q.size()){
            // auto [n,c]=q.front();
            auto n=q.front().first;
            auto c=q.front().second;
            q.pop();
            for(auto x:adj[n]){
                if(!vis[x]){
                    vis[x]=1;
                    q.push({x,n});
                }
                else if(x!=c){
                    return true;
                }
            }
        }
        return false;
    }
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int v, vector<int> adj[]) {
        // Code here
        int vis[v]={0};
        for(int i=0;i<v;i++){
            if(!vis[i]){
                if(bfs(adj,v,vis,i)){
                    return true;
                }
            }
        }
        return false;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends