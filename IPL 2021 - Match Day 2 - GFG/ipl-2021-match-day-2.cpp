//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> max_of_subarrays(vector<int> arr, int n, int k) {
        // your code here
        vector<int> ap;
        int i=0,j=0,mx=INT_MIN;
        while(j<n){
            mx=max(mx,arr[j]);
            if(j-i+1<k){
                j++;
            }
            else if(j-i+1==k){
                ap.push_back(mx);
                if(mx==arr[i]){
                    mx=0;
                    i++;
                    j=i;
                }
                else{
                    i++;
                    j++;
                }
            }
        }
        return ap;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;

    while (t--) {

        int n, k;
        cin >> n >> k;

        vector<int> arr(n);
        for (int i = 0; i < n; i++) cin >> arr[i];
        Solution ob;
        vector<int> res = ob.max_of_subarrays(arr, n, k);
        for (int i = 0; i < res.size(); i++) cout << res[i] << " ";
        cout << endl;
    }

    return 0;
}
// } Driver Code Ends