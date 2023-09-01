//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
#include <string>

using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
    private:
    void solve(int ind,string &s,vector<string> &ans,int digits[],string mapping[],int n){
        if(ind==n){
            ans.push_back(s);
            return;
        }
        int number=digits[ind];
        string k=mapping[number];
        for(int i=0;i<k.size();i++){
            s.push_back(k[i]);
            solve(ind+1,s,ans,digits,mapping,n);
            s.pop_back();
        }
    } 
    public:
    //Function to find list of all words possible by pressing given numbers.
    vector<string> possibleWords(int digits[], int n)
    {
        //Your code here
        string mapping[]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        vector<string> ans;
        if(n==0) return {};
        string s;
        int ind=0;
        solve(ind,s,ans,digits,mapping,n);
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
  
	int T;
	
	cin >> T; //testcases
	
	while(T--){ //while testcases exist
	   int N;
	    
	   cin >> N; //input size of array
	   
	   int a[N]; //declare the array
	   
	   for(int i =0;i<N;i++){
	       cin >> a[i]; //input the elements of array that are keys to be pressed
	   }
	   
	   Solution obj;
	   
	  vector <string> res = obj.possibleWords(a,N);
	  for (string i : res) cout << i << " ";
	   cout << endl;
	}
	
	return 0;
}
// } Driver Code Ends