//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{   
    public: 
    //Function to return a list of integers denoting spiral traversal of matrix.
    vector<int> spirallyTraverse(vector<vector<int> > mat, int r, int c) 
    {
        // code here 
               int n=mat.size();
        int m=mat[0].size();
        vector<int> a;
        int left=0,right=m-1,bottom=n-1,top=0;
        int directon=0;
        while(left<=right && top<=bottom)
        {
        if(directon ==0){
            for(int i=left;i<=right;i++) a.push_back(mat[top][i]);
            top++;
            directon=1;
        }
        else if(directon==1){
            for(int i=top;i<=bottom;i++)a.push_back(mat[i][right]);
            right--;
            directon=2;
        }
        else if(directon==2){
          for(int i=right;i>=left;i--)a.push_back(mat[bottom][i]);
            bottom--;
            directon=3;  
        }
        else if(directon==3){
            for(int i=bottom;i>=top;i--)a.push_back(mat[i][left]);
            left++;
            directon=0; 
        }
        }
       return a;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--) 
    {
        int r,c;
        cin>>r>>c;
        vector<vector<int> > matrix(r); 

        for(int i=0; i<r; i++)
        {
            matrix[i].assign(c, 0);
            for( int j=0; j<c; j++)
            {
                cin>>matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix, r, c);
        for (int i = 0; i < result.size(); ++i)
                cout<<result[i]<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends