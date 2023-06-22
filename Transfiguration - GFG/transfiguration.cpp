//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    
    public:
    int transfigure (string A, string B)
    {
    	// Your code goes here
    	if(A.size()!=B.size()) return -1;
    	map<char,int> mpp;
    	for(int i=0;i<A.size();i++){
    	    mpp[A[i]]++;
    	    mpp[B[i]]--;
    	}
    	for(auto x:mpp){
    	    if(x.second) return -1;
    	}
    	int i=A.size()-1,j=A.size()-1;
    	int ans=0;
    	while(i>=0){
    	    if(A[i]==B[j]){
    	        i--;
    	        j--;
    	    }
    	    else if(A[i]!=B[j]){
    	        i--;
    	        ans++;
    	    }
    	}
    	return ans;
    }
};

//{ Driver Code Starts.


int main () 
{
    int t; cin >> t;
    while (t--)
    {
        string A, B; 
        cin >> A >> B;
        Solution obj;
        cout << obj.transfigure (A, B) << endl;
    }
}
// } Driver Code Ends