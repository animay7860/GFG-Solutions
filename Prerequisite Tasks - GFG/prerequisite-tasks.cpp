//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
	bool isPossible(int n, vector<pair<int, int> >& p) {
      vector<int> adj[n];
        for(auto i:p){
            adj[i.first].push_back(i.second);
        }
        // int ind[n]={0};
        vector<int> ind(n,0);
        for(int i=0;i<n;i++){
            for(auto x:adj[i]){
                ind[x]++;
            }
        }
        queue<int> q;
        for(int i=0;i<n;i++){
            if(ind[i]==0){
                q.push(i);
            }
        }
        vector<int> ans;
        while(!q.empty()){
            auto np=q.front();
            q.pop();
            ans.push_back(np);
            for(auto it:adj[np]){
                ind[it]--;
                if(ind[it]==0){
                    q.push(it);
                }
            }
        }
        if(ans.size()==n){
            return true;
        }
        return false;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
    	int N, P;
        vector<pair<int, int> > prerequisites;
        cin >> N;
        cin >> P;
        for (int i = 0; i < P; ++i) {
            int x, y;
            cin >> x >> y;
            prerequisites.push_back(make_pair(x, y));
        }
        // string s;
        // cin>>s;
        Solution ob;
        if (ob.isPossible(N, prerequisites))
            cout << "Yes";
        else
            cout << "No";
        cout << endl;
	}
	return 0;
}
// } Driver Code Ends