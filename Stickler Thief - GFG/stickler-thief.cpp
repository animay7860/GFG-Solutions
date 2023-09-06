//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

// } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum money the thief can get.
       int solve(int ind,vector<int> &dp,int nums[]){
       if(ind==0) return nums[ind];
       if(ind<0) return 0;
       if(dp[ind]!=-1)return dp[ind];
       int pick=nums[ind]+solve(ind-2,dp,nums);
       int not_pick=0+solve(ind-1,dp,nums);

       return dp[ind]=max(pick,not_pick);
   }
    int FindMaxSum(int nums[], int n)
    {
        // Your code here
        //  int n=nums.size();
       vector<int> dp(n,-1);
       int ans=solve(n-1,dp,nums);
       return ans; 
    }
};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
	int t;
	cin>>t;
	while(t--)
	{
	    //taking number of houses
		int n;
		cin>>n;
		int a[n];
		
		//inserting money of each house in the array
		for(int i=0;i<n;++i)
			cin>>a[i];
		Solution ob;
		//calling function FindMaxSum()
		cout<<ob.FindMaxSum(a,n)<<endl;
	}
	return 0;
}

// } Driver Code Ends