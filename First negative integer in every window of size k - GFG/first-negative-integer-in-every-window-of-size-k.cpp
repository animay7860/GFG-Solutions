//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

vector<long long> printFirstNegativeInteger(long long int arr[],
                                             long long int n, long long int k);

// Driver program to test above functions
int main() {
    long long int t, i;
    cin >> t;
    while (t--) {
        long long int n;
        cin >> n;
        long long int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        long long int k;
        cin >> k;

        vector<long long> ans = printFirstNegativeInteger(arr, n, k);
        for (auto it : ans) cout << it << " ";
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends


vector<long long> printFirstNegativeInteger(long long int a[],long long int n, long long int k) {
            vector<long long> ans;
            list<long long> ls;
            long long int i=0,j=0;
            while(j<n){
                if(a[j]<0){
                   ls.push_back(a[j]); 
                }
                if(j-i+1<k){
                    j++;
                }
                else if(j-i+1==k){
                    ans.push_back(ls.front());
                    if(a[i]==ls.front()){
                        ls.pop_front();
                        i++;
                        j++;
                    }
                    else{
                        i++;
                        j++;
                    }
                }
            }
              return ans;                                   
 }