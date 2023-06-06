//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
    string b;
    map<string,int> mpp;
    vector<vector<string>> ans;
private:
    void dfs(string word,vector<string> &seq){
        if(word==b){
            vector<string> temp=seq;
            reverse(temp.begin(),temp.end());
            ans.push_back(temp);
            return;
        }
        int steps=mpp[word];
        int sz=word.size();
        for(int i=0;i<sz;i++){
            char original=word[i];
            for(char ch='a';ch<='z';ch++){
                word[i]=ch;
                if(mpp.find(word)!=mpp.end() and mpp[word]==steps-1){
                    seq.push_back(word);
                    dfs(word,seq);
                    seq.pop_back();
                }
            }
            word[i]=original;
        }
    }    
public:
    vector<vector<string>> findSequences(string beginWord, string endWord, vector<string>& wordList) {
        // code here
        set<string> st(wordList.begin(),wordList.end());
        queue<string> q;
        b=beginWord;
        q.push(beginWord);
        int n=beginWord.size();
        mpp[beginWord]=1;
        st.erase(beginWord);
        while(!q.empty()){
            auto word=q.front();
            int steps=mpp[word];
            q.pop();
            if(word==endWord) break;
            for(int i=0;i<n;i++){
                for(char ch='a';ch<='z';ch++){
                 string replacedWord = word;
                  replacedWord[i] = ch;
                    if(st.count(replacedWord)>0){
                        st.erase(replacedWord);
                        q.push(replacedWord);
                        mpp[replacedWord]=steps+1;
                    }
                }
            }
        }
        if(mpp.find(endWord)!=mpp.end()){
            vector<string> seq;
            seq.push_back(endWord);
            dfs(endWord,seq);
        }
        return ans;
    }
};

//{ Driver Code Starts.

bool comp(vector<string> a, vector<string> b)
{
    string x = "", y = "";
    for(string i: a)
        x += i;
    for(string i: b)
        y += i;
    
    return x<y;
}

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<string>wordList(n);
		for(int i = 0; i < n; i++)cin >> wordList[i];
		string startWord, targetWord;
		cin >> startWord >> targetWord;
		Solution obj;
		vector<vector<string>> ans = obj.findSequences(startWord, targetWord, wordList);
		if(ans.size()==0)
		    cout<<-1<<endl;
		else
		{
		    sort(ans.begin(), ans.end(), comp);
            for(int i=0; i<ans.size(); i++)
            {
                for(int j=0; j<ans[i].size(); j++)
                {
                    cout<<ans[i][j]<<" ";
                }
                cout<<endl;
            }
		}
	}
	return 0;
}
// } Driver Code Ends