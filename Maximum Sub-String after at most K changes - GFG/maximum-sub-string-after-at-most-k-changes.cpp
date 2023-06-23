//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
		int characterReplacement(string s, int k){
		    // Code here
		    int i =0 ;
      int j =0 ;
      int n =s.length();
      unordered_map<char,int> mpp;
      int mx=0;
      int ans=-1;
      int window_size=0;
      while(j<n){
        mpp[s[j]]++;
          mx=max(mx,mpp[s[j]]);
          window_size=j-i+1;
        if(window_size-mx>k){
          mpp[s[i]]--;
          i++;
        }
        window_size=j-i+1;
        ans=max(ans,window_size);
         j++;
      }
      return ans;
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string s;
		cin >> s;
		int k;
		cin >> k;
		Solution obj;
		int ans = obj.characterReplacement(s, k);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends