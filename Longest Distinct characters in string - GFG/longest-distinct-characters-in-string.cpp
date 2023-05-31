//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
int longestSubstrDistinctChars (string S);
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string S; cin >> S;

        cout << longestSubstrDistinctChars (S) << endl;
    }
}

// Contributed By: Pranay Bansal

// } Driver Code Ends


int longestSubstrDistinctChars (string s)
{
    // your code here
    int n=s.size();
        set<char> st;
        int i=0,j=0;
        int ans=0;
        while(i<n and j<n){
          if(st.find(s[i])==st.end()){
            st.insert(s[i]);
            i++;
            int temp=st.size();
            ans=max(ans,temp);
          }
          else{
               st.erase(s[j]);
               j++;
          }
        }
      return ans;
}