//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    //Complete this function
    void solve(string s,int ind,vector<string>& ans,string path,int visited[]){
        if(ind==s.size()){
            ans.push_back(path);
            return;
        }
        for(int i=0;i<s.size();i++){
            if(!visited[i]){
                visited[i]=1;
                path.push_back(s[i]);
                solve(s,ind+1,ans,path,visited);
                visited[i]=0;
                path.pop_back();
            }
        }
    }
    vector<string> permutation(string s)
    {
        //Your code here
        string path;
        vector<string> ans;
        int visited[s.length()] = {0};
        int ind=0;
        solve(s,ind,ans,path,visited);
        sort(ans.begin(),ans.end());
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		string S;
		cin>>S;
		Solution ob;
		vector<string> vec = ob.permutation(S);
		for(string s : vec){
		    cout<<s<<" ";
		}
		cout<<endl;
	
	}
	return 0;
}
// } Driver Code Ends