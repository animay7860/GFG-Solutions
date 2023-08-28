//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
    private:
    void solve(int ind,int n,int s,int target,vector<int>& temp,vector<vector<int>>& ans,vector<int>& c){
        if(s==target){
            ans.push_back(temp);
            return;
        }
        else if(s>target){
            return;
        }
        for(int i=ind;i<n;i++){
            if(i!=ind and c[i]==c[i-1]) continue;
            s+=c[i];
            temp.push_back(c[i]);
            solve(i+1,n,s,target,temp,ans,c);
            s-=c[i];
            temp.pop_back();
        }
    }  
  public:
  
    vector<vector<int>> combinationSum2(vector<int> &c, int target) {
        // Write your code here
              int n=c.size();
       int s=0;
       vector<int> temp;
       vector<vector<int>> ans;
       sort(c.begin(),c.end());
       solve(0,n,s,target,temp,ans,c);
       return ans;
    }
};

//{ Driver Code Starts.
int main() {

    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> candidates(n);
        for (int i = 0; i < n; ++i) {
            cin >> candidates[i];
        }
        // char marker;
        // cin >> marker;

        Solution obj;

        vector<vector<int>> comb = obj.combinationSum2(candidates, k);
        sort(comb.begin(), comb.end());
        cout << "[ ";
        for (int i = 0; i < comb.size(); i++) {
            cout << "[ ";
            for (int j = 0; j < comb[i].size(); j++) {
                cout << comb[i][j] << " ";
            }
            cout << "]";
        }
        cout << " ]\n";

        // cout << "\n~\n";
    }
    fclose(stdout);
    return 0;
}

// } Driver Code Ends