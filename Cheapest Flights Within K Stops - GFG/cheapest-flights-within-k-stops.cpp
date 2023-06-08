//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int CheapestFLight(int n, vector<vector<int>>& flights, int src, int dst, int k)  {
        // Code here
        vector<pair<int,int>> adj[n+1];
        int p=flights.size();
        for(auto x:flights){
            adj[x[0]].push_back({x[1],x[2]});
        }
        queue<pair<int,pair<int,int>>> q;
        vector<int> dist(n,1e9);
        q.push({0,{src,0}});
        while(!q.empty()){
            auto stop=q.front().first;
            auto node=q.front().second.first;
            auto dis=q.front().second.second;
            q.pop();
            if(stop>k){
                break;
            }
            for(auto x:adj[node]){
                auto nxt_node=x.first;
                auto edw=x.second;
                if(edw+dis<dist[nxt_node]){
                    dist[nxt_node]=edw+dis;
                    q.push({stop+1,{nxt_node,dist[nxt_node]}});
                }
            }
        }
        if(dist[dst]==1e9) return -1;
        return dist[dst];
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n; cin>>n;
        int edge; cin>>edge;
        vector<vector<int>> flights;
        
        for(int i=0; i<edge; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            flights.push_back(temp);
        }
        
        int src,dst,k;
        cin>>src>>dst>>k;
        Solution obj;
        cout<<obj.CheapestFLight(n,flights,src,dst,k)<<"\n";
    }
    return 0;
}
// } Driver Code Ends