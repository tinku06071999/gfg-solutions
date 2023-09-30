//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends


class Solution
{   
    public:
    //Function to modify the matrix such that if a matrix cell matrix[i][j]
    //is 1 then all the cells in its ith row and jth column will become 1.
    void booleanMatrix(vector<vector<int> > &matrix)
    {
        // code here 
        int rows = matrix.size();
        int cols = matrix[0].size();
        vector<vector<int>>v(rows,vector<int>(cols,0));
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(matrix[i][j]==1)v[i][j]=1;
            }
        }
        int i=0,j=0;
    //   while(i<rows){
    //       while(j<cols){
    //             if(matrix[i][j]==1){
    //                 for(int k=0;k<rows;k++)matrix[k][j]=1;
    //                 for(int l=0;l<cols;l++ )matrix[i][l]=1;
    //                 j++;
    //                 break;
    //             }
    //             j++;
    //         }
    //         i++;
    //     }
      for(int i=0;i<rows;i++){
          for(int j=0;j<cols;j++){
          if(v[i][j]==1){
              int r = i;
              int c = j;
              for(int k=0;k<rows;k++)matrix[k][c]=1;
              for(int l=0;l<cols;l++)matrix[r][l]=1;
          }
       }
      }
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin>>t;
    while(t--) 
    {
        int row, col;
        cin>> row>> col;
        vector<vector<int> > matrix(row); 
        for(int i=0; i<row; i++)
        {
            matrix[i].assign(col, 0);
            for( int j=0; j<col; j++)
            {
                cin>>matrix[i][j];
            }
        }
        
        Solution ob;
        ob.booleanMatrix(matrix);


        for (int i = 0; i < row; ++i)
        {
            for (int j = 0; j < col; ++j)
            {
                cout<<matrix[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}



// } Driver Code Ends