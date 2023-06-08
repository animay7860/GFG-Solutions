//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int countPaths(int n, vector<vector<int>>& roads) {
         vector<pair<long long,long long>>adj[n];
        
        for(auto it: roads)
        {
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        
        priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>>pq;
    
        vector<long long> dist(n,LONG_MAX),ways(n,0);
        dist[0]=0;
        ways[0]=1;
        int mod=(1e9 +7);
        pq.push({0,0});
        while(!pq.empty())
        {
          long long d=pq.top().first;
          long long int node=pq.top().second;
          pq.pop();
          for(auto it:adj[node])
          {
              long long adjnode=it.first;
              long long int edgwt=it.second;
      //this is the first time i have entered with short distance 
              if((d+edgwt)<dist[adjnode])
              {
                  dist[adjnode]=d+edgwt;
                  ways[adjnode]=ways[node];
                  pq.push({dist[adjnode],adjnode});
              } else if((d+edgwt)==dist[adjnode])
              {
                   ways[adjnode]=((ways[adjnode]%mod + ways[node])%mod)%mod;
              }
          }
         
        }
        return ways[n-1]%mod;
        // code here
        // vector<int> dis(n,1e9),ways(n,0);
        // int mod=int(1e9+7);
        // vector<pair<int,int>> adj[n];
        // for(auto x:roads){
        //     adj[x[0]].push_back({x[1],x[2]});
        //     adj[x[1]].push_back({x[0],x[2]});
        // }
        // dis[0]=0;
        // ways[0]=1;
        // priority_queue <pair<int,int>, vector<pair<int,int>>, 
        // greater<pair<int,int>> > pq;
        // pq.push({0,0});
        // while(!pq.empty()){
        //     auto node=pq.top().second;
        //     auto dist=pq.top().first;
        //     pq.pop();
        //     for(auto x:adj[node]){
        //         auto nxt_node=x.first;
        //         auto edw=x.second;
        //         if(dist+edw<dis[nxt_node]){
        //             dis[nxt_node]=dist+edw;
        //             pq.push({dis[nxt_node],nxt_node});
        //             ways[nxt_node]=ways[node];
        //         }
        //         else if(dist+edw==dis[nxt_node]){
        //             ways[nxt_node]=(ways[nxt_node]+ways[node])%mod;
        //         }
        //     }
        // }
        // return ways[n-1]%mod;
    }
};

//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        int u, v;

        vector<vector<int>> adj;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution obj;
        cout << obj.countPaths(n, adj) << "\n";
    }

    return 0;
}
// } Driver Code Ends