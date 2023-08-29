//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
    private:
    void solve(int ind,vector<int>& nums,vector<int>& temp,vector<int>& fre,set<vector<int>>& ans){
        if(temp.size()==nums.size()){
            ans.insert(temp);
            return;
        }
        for(int i=0;i<nums.size();i++){
            if(!fre[i]){
             temp.push_back(nums[i]);
             fre[i]=1;
             solve(ind,nums,temp,fre,ans);
             temp.pop_back();
             fre[i]=0;
            }
        }
    }
  public:
    vector<vector<int>> uniquePerms(vector<int> &nums ,int n) {
        // code here
        set<vector<int>> ans;
        vector<int> temp;
        
        // int n=nums.size();
        vector<int> fre(n,0);
        solve(0,nums,temp,fre,ans);
        vector<vector<int>> a(ans.begin(),ans.end());
        return a;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        
        cin>>n;
        vector<int> arr(n);
        
        for(int i=0 ; i<n ; i++)
            cin>>arr[i];

        Solution ob;
        vector<vector<int>> res = ob.uniquePerms(arr,n);
        for(int i=0; i<res.size(); i++)
        {
            for(int j=0; j<n; j++)
            {
                cout<<res[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends