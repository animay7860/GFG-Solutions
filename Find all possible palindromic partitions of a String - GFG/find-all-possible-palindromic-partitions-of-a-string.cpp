//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
  bool is_valid(int start,int end,string s){
    while(start<=end){
        if(s[start++]!=s[end--]){
        return false;
    }
    }
    return true;
}
 void solve(int ind,string s,vector<string>& path,vector<vector<string>>& ans){
  if(ind==s.size()){
   ans.push_back(path);
   return;
  }
  for(int i=ind;i<s.size();i++){
      if(is_valid(ind,i,s)){
          path.push_back(s.substr(ind,i-ind+1));
          solve(i+1,s,path,ans);
          path.pop_back();
      }
  }
 } 
    vector<vector<string>> allPalindromicPerms(string s) {
        // code here
        vector<vector<string>> ans;
        vector<string> path;
        solve(0,s,path,ans);
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        
        cin>>S;

        Solution ob;
        vector<vector<string>> ptr = ob.allPalindromicPerms(S);
        
        for(int i=0; i<ptr.size(); i++)
        {
            for(int j=0; j<ptr[i].size(); j++)
            {
                cout<<ptr[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}
// } Driver Code Ends