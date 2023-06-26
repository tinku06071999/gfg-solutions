//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
    private:
      void dfs(int sr, int sc, vector<vector<int>>&vis, vector<vector<char>> mat, int delrow[],int delcol[], int n, int m){
          vis[sr][sc]=1;
       for(int i=0;i<4;i++){
           int nrow = sr+delrow[i];
           int ncol = sc+delcol[i];
           if(nrow>=0 && ncol>=0 && nrow<n && ncol<m && !vis[nrow][ncol] && mat[nrow][ncol]=='O'){
               dfs(nrow,ncol,vis,mat,delrow,delcol,n,m);
           }
        }
      }
public:
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        // code here
       
         int delrow[]={-1,0,+1,0};
            int delcol[]={0,+1,0,-1};
            vector<vector<int>>vis(n,vector<int>(m,0));
            int strt_row=0;
            int strt_col=0;
            for(int i=0;i<m;i++){
                if(mat[0][i]=='O'){
                    dfs(0,i,vis, mat,delrow,delcol,n,m);
                }
            }
            for(int i=0;i<n;i++){
                if(mat[i][0]=='O'){
                    dfs(i,0,vis, mat,delrow,delcol,n,m);
                }
            }
            for(int i=0;i<m;i++){
                if(mat[n-1][i]=='O'){
                    dfs(n-1,i,vis, mat,delrow,delcol,n,m);
                }
            }
            for(int i=0;i<n-1;i++){
                if(mat[i][m-1]=='O'){
                    dfs(i,m-1,vis, mat,delrow,delcol,n,m);
                }
            }
            for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                    if(mat[i][j]=='O' && !vis[i][j]){
                        mat[i][j] = 'X';
                    }
                }
            }
            return mat;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<char>> mat(n, vector<char>(m, '.'));
        for(int i = 0;i < n;i++)
            for(int j=0; j<m; j++)
                cin>>mat[i][j];
        
        Solution ob;
        vector<vector<char>> ans = ob.fill(n, m, mat);
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                cout<<ans[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends