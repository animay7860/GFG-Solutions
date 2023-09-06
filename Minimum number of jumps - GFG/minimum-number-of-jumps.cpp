//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// Function to return minimum number of jumps to end of array

class Solution{
  public:
    int minJumps(int arr[], int n){
        // Your code here
        if(arr[0]==0) return -1;
        if(n==1) return 0;
            int step=arr[0];
            int mx_reach=arr[0];
            int jump=1;
            int i=1;
            for(i=1;i<n;i++){
                if(i==n-1) return jump;
                mx_reach=max(mx_reach,arr[i]+i);
                step--;
                if(step==0){
                    jump++;
                    if(mx_reach<=i){
                        return -1;
                    }
                    step=mx_reach-i;
                }
            }
        return -1;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,i,j;
        cin>>n;
        int arr[n];
        for(int i=0; i<n; i++)
            cin>>arr[i];
        Solution obj;
        cout<<obj.minJumps(arr, n)<<endl;
    }
    return 0;
}

// } Driver Code Ends