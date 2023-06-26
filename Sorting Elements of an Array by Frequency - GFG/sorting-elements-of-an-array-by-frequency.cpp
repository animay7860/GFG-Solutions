//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends
class Solution{
    public:
    //Complete this function
    //Function to sort the array according to frequency of elements.
    static bool cmp(pair<int,int> a,pair<int,int> b){
        if(a.second==b.second){
            return a.first<b.first;
        }
        else{
            return a.second>b.second;
        }
    }
    vector<int> sortByFreq(int arr[],int n)
    {
        //Your code here
        map<int,int> mpp,mpp1;
        vector<pair<int,int>> vp;
        for(int i=0;i<n;i++){
            mpp[arr[i]]++;
        }
        for(auto it:mpp){
            vp.push_back({it.first,it.second});
        }
        vector<int> ans;
        sort(vp.begin(),vp.end(),cmp);
        // for(auto x:vp ){
        //     ans.push_back(x.second);
        // }
        for(int i=0;i<vp.size();i++){
            for(int j=0;j<vp[i].second;j++){
                ans.push_back(vp[i].first);
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
	
	
	int t;
	cin >> t;
	
	
	while(t--){
	    
	    
	    int n;
	    cin >> n;
	    
	    int a[n+1];
	    
	    for(int i = 0;i<n;i++){
	        cin >> a[i];
	    }
	    Solution obj;
	    vector<int> v;
	    v = obj.sortByFreq(a,n);
	    for(int i:v)
	        cout<<i<<" ";
	    cout << endl;
	}
	
	return 0;
}


// } Driver Code Ends