//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int MinimumEffort(vector<vector<int>>& heights) {
        // Code here
    priority_queue <pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>,
     greater<pair<int,pair<int,int>>>> pq;
     int n=heights.size();
     int m=heights[0].size();
     pq.push({0,{0,0}});
     vector<vector<int>> dist(n,vector<int> (m,1e9));
     while(!pq.empty()){
         auto dis=pq.top().first;
         int r=pq.top().second.first;
         int c=pq.top().second.second;
         pq.pop();
        vector<int> x = {+1, -1, 0, 0};
        vector<int> y = {0, 0, +1, -1};
        if(r==n-1 and c==m-1) return dis;
        for(int i=0;i<4;i++){
            int nrow=r+x[i];
            int ncol=c+y[i];
            if(nrow>=0 and ncol>=0 and nrow<n and ncol<m){
                int max_effort=max(dis,abs(heights[nrow][ncol]-heights[r][c]));
                if(max_effort<dist[nrow][ncol]){
                    dist[nrow][ncol]=max_effort;
                    pq.push({dist[nrow][ncol],{nrow,ncol}});
                }
            }
        }

     }
     return 0;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n,m; cin>>n>>m;
        vector<vector<int>> heights;
       
        for(int i=0; i<n; ++i){
            vector<int> temp;
            for(int j=0; j<m; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            heights.push_back(temp);
        }
       
        Solution obj;
        cout<<obj.MinimumEffort(heights)<<"\n";
    }
    return 0;
}
// } Driver Code Ends