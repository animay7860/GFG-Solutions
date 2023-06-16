//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution{
public:
    vector<int> findTwoElement(vector<int> arr, int n) {
        // code here
        unordered_map<int,int> mpp;
        unordered_set<int> st;
        vector<int> ans;
        for(auto x:arr){
            mpp[x]++;
        }
        for(auto it:mpp){
            if(it.second==2){
                ans.push_back(it.first);
                break;
            }
        }
        for(int i=0;i<n;i++){
            st.insert(arr[i]);
        }
        for(int i=1;i<=n;i++){
            if(st.find(i)==st.end()){
                ans.push_back(i);
                break;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}
// } Driver Code Ends