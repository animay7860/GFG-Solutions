//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& edges, int n,int M, int src){
        // code here
        vector<int> adj[n];
        vector<int> ans(n,1e9);
        for(auto it:edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        // coz of undirected graph
        // Now we have our undirected graph
        // lets do the bfs traversal in it
        queue<int> q;
        q.push(src);
        ans[src]=0;
        while(!q.empty()){
            auto node=q.front();
            q.pop();
            for(auto x:adj[node]){
                // ans[x]=min(ans[x],ans[node]+1);
                // q.push(x);
                if(ans[x]>ans[node]+1){
                    ans[x]=ans[node]+1;
                    q.push(x);
                }
            }
        }
        for(int i=0;i<n;i++){
            if(ans[i]==1e9){
                ans[i]=-1;
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
        int n, m; cin >> n >> m;
        vector<vector<int>> edges;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for(int j=0; j<2; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        int src; cin >> src;

        Solution obj;

        vector<int> res = obj.shortestPath(edges, n, m, src);

        for (auto x : res){
            cout<<x<<" ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends