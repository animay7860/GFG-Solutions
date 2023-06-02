//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find the smallest window in the string s consisting
    //of all the characters of string p.
    string smallestWindow (string s, string t)
    {
        
         int n=s.length();
        int i=0,j=0;
        unordered_map<char,int> mpp;
        for(int i=0;i<t.length();i++){
           mpp[t[i]]++;
        }
        int mn=INT_MAX;
        int count=mpp.size();
        string ans="";
        while(j<n){
         if(mpp.find(s[j])!=mpp.end()){
             mpp[s[j]]--;
             if(mpp[s[j]]==0){
               count--;
             }
             
         }
        //  if(count==0){
            // mn=min(mn,j-i+1);
            while(count==0){
                if(mn>j-i+1){
                mn=min(mn,j-i+1);
                ans=s.substr(i,j-i+1);
                }
                
                if(mpp.find(s[i])!=mpp.end()){
                    mpp[s[i]]++;
                    if(mpp[s[i]]==1){
                        count++;
                    }
                }
                i++;
            }
            
        //  }
         j++;
        }
        if(mn==INT_MAX){
            return "-1";
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        string pat;
        cin>>pat;
        Solution obj;
        cout<<obj.smallestWindow(s, pat)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends