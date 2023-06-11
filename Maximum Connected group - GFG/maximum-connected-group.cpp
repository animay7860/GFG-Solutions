//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class DisjointSet {
public: 
  vector<int> rank, parent, size; 
    DisjointSet(int n) {
        rank.resize(n+1, 0); 
        parent.resize(n+1);
        size.resize(n+1); 
        for(int i = 0;i<=n;i++) {
            parent[i] = i; 
            size[i] = 1; 
        }
    }

    int findUPar(int node) {
        if(node == parent[node])
            return node; 
        return parent[node] = findUPar(parent[node]); 
    }

    void unionByRank(int u, int v) {
        int ulp_u = findUPar(u); 
        int ulp_v = findUPar(v); 
        if(ulp_u == ulp_v) return; 
        if(rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v; 
        }
        else if(rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u; 
        }
        else {
            parent[ulp_v] = ulp_u; 
            rank[ulp_u]++; 
        }
    }

    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u); 
        int ulp_v = findUPar(v); 
        if(ulp_u == ulp_v) return; 
        if(size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v; 
            size[ulp_v] += size[ulp_u]; 
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v]; 
        }
    }
}; 
class Solution {
  public:
    int MaxConnection(vector<vector<int>>& grid) {
        // code here
        int n=grid.size();
        DisjointSet ds(n*n);
        for(int row=0;row<n;row++){
            for(int col=0;col<n;col++){
                if(grid[row][col]==0) continue;
                int x[]={1,-1,0,0};
                int y[]={0,0,1,-1};
                for(int i=0;i<4;i++){
                    int nrow=row+x[i];
                    int ncol=col+y[i];
                    if(ncol<n and nrow<n and nrow>=0 and ncol>=0 
                    and grid[nrow][ncol]==1){
                         int node=row*n+col;
                         int adjnode=nrow*n+ncol;
                         ds.unionBySize(node,adjnode);
                    }
                }
            }
        }
        int mx=0;
        for(int row=0;row<n;row++){
            for(int col=0;col<n;col++){
                if(grid[row][col]==1) continue;
                int x[]={1,-1,0,0};
                int y[]={0,0,1,-1};
                set<int> st;
                for(int i=0;i<4;i++){
                    int nrow=row+x[i];
                    int ncol=col+y[i];
                    if(ncol<n and nrow<n and nrow>=0 and ncol>=0 
                    and grid[nrow][ncol]==1){
                        st.insert(ds.findUPar(nrow*n + ncol));
                    }
                }
                int total=0;
                for(auto it:st){
                  total+=ds.size[it];
                }
                mx=max(mx,total+1);
            }
        }
    //    mx=max(mx,n*n);
        for(int i=0;i<n*n;i++){
            mx=max(mx,ds.size[ds.findUPar(i)]);
        }
        return mx;
    }
};


//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> grid(n, vector<int>(n));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> grid[i][j];
            }
        }

        Solution obj;
        cout<<obj.MaxConnection(grid)<<"\n";
    }
}

// } Driver Code Ends