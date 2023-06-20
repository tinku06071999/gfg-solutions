//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{   
    public: 
    //Function to return a list of integers denoting spiral traversal of matrix.
    vector<int> spirallyTraverse(vector<vector<int> > matrix, int r, int c) 
    {
        // code here 
        int strt_row=0;
        int strt_col=0;
        int end_row=r-1;
        int end_col=c-1;
        int total = r*c;
        int count=0;
        vector<int>v;
        while(count<total){
            for(int i=strt_col;i<=end_col && count<total ;i++){
                v.push_back(matrix[strt_row][i]);
                count++;
            }
            strt_row++;
            for(int i=strt_row;i<=end_row && count<total;i++){
                v.push_back(matrix[i][end_col]);
                count++;
            }
            end_col--;
            for(int i=end_col;i>=strt_col && count<total;i--){
                v.push_back(matrix[end_row][i]);
                count++;
            }
            end_row--;
            for(int i=end_row;i>=strt_row && count<total;i--){
                v.push_back(matrix[i][strt_col]);
                count++;
            }
            strt_col++;
        }
        return v;
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