//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:

	// Function to find maximum product subarray
	long long maxProduct(vector<int> nums, int n) {
	    // code here
	           
        long long pd=1;
        long long ans=INT_MIN;
        for(int i=0;i<n;i++){
            pd=pd*nums[i];
            ans=max(ans,pd);
            
            if(nums[i]==0){
                pd=1;
            }
        }
        pd=1;
        long long mn=INT_MIN;
        for(int i=n-1;i>=0;i--){
            pd=pd*nums[i];
            mn=max(mn,pd);
            
            if(nums[i]==0){
                pd=1;
            }
        }
        return max(ans,mn);
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        vector<int> arr(n);
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.maxProduct(arr, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends