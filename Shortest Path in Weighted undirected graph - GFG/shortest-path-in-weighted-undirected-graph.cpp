//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        // Code here
        vector<int> path;
        vector<pair<int,int>> adj[n+1];
        for(auto x:edges){
            adj[x[0]].push_back({x[1],x[2]});
            adj[x[1]].push_back({x[0],x[2]});
        }
        vector<int> parent(n+1);
        vector<int> dis(n+1,1e9);
        dis[1]=0;
        for(int i=1;i<=n;i++){
            parent[i]=i;
        }
        priority_queue <pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pq;
        pq.push({0,1});
        while(!pq.empty()){
            auto node=pq.top().second;
            auto dist=pq.top().first;
            pq.pop();
            for(auto x:adj[node]){
                auto adjnode=x.first;
                auto edjw=x.second;
                if(dist+edjw<dis[adjnode]){
                    dis[adjnode]=dist+edjw;
                    pq.push({dis[adjnode],adjnode});
                    parent[adjnode]=node;
                }
            }
        }
        int k=n;if(dis[n]==1e9) return {-1};
        while(parent[k]!=k){
            path.push_back(k);
            k=parent[k];
        }
        path.push_back(1);
        reverse(path.begin(),path.end());
        return path;
    }
};

//{ Driver Code Starts.
int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
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