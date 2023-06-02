//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    private:
bool bfs(int src,vector<int>g[],vector<int> &color){
        color[src]=0;
        queue<int> q;
        q.push(src);
        while(!q.empty()){
            auto x=q.front();
            q.pop();
            for(auto i:g[x]){
                if(color[i]==-1){
                    color[i]=!color[x];
                    q.push(i);
                }
                else if(color[i]==color[x]){
                    return false;
                }
            }
        } 
        return true;
    }    
    
public:

	bool isBipartite(int n, vector<int>g[]){
	    // Code here
	    vector<int> color(n,-1);
        for(int i=0;i<n;i++){
            if(color[i]==-1){
                if(!bfs(i,g,color)) return false;
            }
        }
        return true;
	}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}
// } Driver Code Ends