//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  void dfs(int sr, int sc, vector<vector<int>> &grid, vector<int>delrow, vector<int>delcol,int n, int m){
        grid[sr][sc]=0;
        for(int i=0;i<4;i++){
            int nr = sr+delrow[i];
            int nc = sc+delcol[i];
            if(nc>=0 && nr>=0 && nc<m && nr<n && grid[nr][nc]==1)dfs(nr,nc,grid,delrow,delcol,n,m);
        }
    }
  public:
    int numberOfEnclaves(vector<vector<int>> &grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<int>delrow = {-1,0,+1,0};
        vector<int>delcol = {0,+1,0,-1};
        for(int i=0;i<n;i++){
            if(grid[i][0]==1)dfs(i,0,grid,delrow,delcol,n,m);
            if(grid[i][m-1]==1)dfs(i,m-1,grid,delrow,delcol,n,m);
        }
        for(int i=0;i<m;i++){
            if(grid[0][i]==1)dfs(0,i,grid,delrow,delcol,n,m);
            if(grid[n-1][i]==1)dfs(n-1,i,grid,delrow,delcol,n,m);
        }
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1)count++;
            }
        }
        return count;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.numberOfEnclaves(grid) << endl;
    }
}
// } Driver Code Ends