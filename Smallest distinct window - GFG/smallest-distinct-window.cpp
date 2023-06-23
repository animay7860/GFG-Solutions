//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int findSubString(string s)
    {
        // Your code goes here 
        unordered_set<char> st;
        for(auto i:s){
            st.insert(i);
        }
        int ans=1e9;
        unordered_map<char,int> mpp;
        int k=st.size();
        int i=0,j=0;
        while(j<s.size()){
            mpp[s[j]]++;
            if(mpp.size()<k) j++;
            else if(mpp.size()==k){
            
            while(mpp.size()==k){
                  mpp[s[i]]--;
               if(mpp[s[i]]==0){
                   mpp.erase(s[i]);
               }
               i++;
            }

               j++;
               ans=min(ans,j-i+1);
            }
            
        }
        return ans;
    }
};

//{ Driver Code Starts.
// Driver code
int main() {
    int t;
    cin >> t;
    while (t--) {

        string str;
        cin >> str;
        Solution ob;
        cout << ob.findSubString(str) << endl;
    }
    return 0;
}
// } Driver Code Ends