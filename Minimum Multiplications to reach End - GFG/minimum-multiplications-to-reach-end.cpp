//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        // code here
        queue<pair<int,int>> q;
        int mod=100000;
        q.push({0,start});
        vector<int> dis(100000,1e9);
        while(!q.empty()){
            auto steps=q.front().first;
            auto node=q.front().second;
            q.pop();
            if(node==end) return steps;
            for(auto i: arr){
                int num=(i*node)%mod;
                if(steps+1<dis[num]){
                    dis[num]=steps+1;
                    q.push({dis[num],num});
                }
            }
        }
        return -1;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        int start, end;
        cin >> start >> end;
        Solution obj;
        cout << obj.minimumMultiplications(arr, start, end) << endl;
    }
}

// } Driver Code Ends