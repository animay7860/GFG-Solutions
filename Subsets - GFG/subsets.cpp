//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
    private:
    void solve(int ind,vector<int>& nums,vector<vector<int>>& ans,vector<int> temp,int n){
        if(ind>=n){
            ans.push_back(temp);
            return;
        }
        temp.push_back(nums[ind]);
        solve(ind+1,nums,ans,temp,n);
        temp.pop_back();
        solve(ind+1,nums,ans,temp,n);
        
    } 
    public:
    vector<vector<int> > subsets(vector<int>& nums)
    {
        //code here
        int n=nums.size();
        vector<vector<int>> ans;
        vector<int> temp;
        solve(0,nums,ans,temp,n);
        sort(ans.begin(),ans.end());
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin >> t;

	while (t--)
	{
		int n, x;
		cin >> n;

		vector<int> array;
		for (int i = 0; i < n; i++)
		{
			cin >> x;
			array.push_back(x);
		}
        
        
        Solution ob;
		vector<vector<int> > res = ob.subsets(array);

		// Print result
		for (int i = 0; i < res.size(); i++) {
			for (int j = 0; j < res[i].size(); j++)
				cout << res[i][j] << " ";
			cout << endl;
		}

		
	}

	return 0;
}
// } Driver Code Ends