//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    private:
    int dfs(int sr, int sc, vector<vector<int>> &vis, vector<vector<int>> &grid, int delrow[], int delcol[], int n, int m,int count){
     vis[sr][sc] = 1;
    count++;
     for(int i=0;i<8;i++){
         int nrow = sr+delrow[i];
         int ncol = sc+delcol[i];
         if(nrow>=0 && ncol>=0 && nrow<n && ncol<m && !vis[nrow][ncol] && grid[nrow][ncol]==1){
           count=dfs(nrow, ncol, vis, grid, delrow, delcol,n,m,count);
         }
     }
         return count;
 }
    public:
    //Function to find unit area of the largest region of 1s.
    int findMaxArea(vector<vector<int>>& grid) {
        // Code here
        int n = grid.size();
        int m = grid[0].size();
        int count=0;
        int maxi=0;
         int delrow[] = {0,-1,-1,-1,0,+1,+1,+1};
        int delcol[] = {-1,-1,0,+1,+1,+1,0,-1};
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
           for(int j=0;j<m;j++){
                if(grid[i][j]==1 && !vis[i][j]){
                 count = dfs(i,j,vis,grid,delrow,delcol,n,m,0);
                 maxi  = max(count,maxi);
                }
            }
        }
       
        return maxi;
    
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.findMaxArea(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends