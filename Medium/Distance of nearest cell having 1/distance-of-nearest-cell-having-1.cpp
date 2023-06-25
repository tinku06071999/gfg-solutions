//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find distance of nearest 1 in the grid for each cell.
	vector<vector<int>>nearest(vector<vector<int>>grid)
	{
	    // Code here
	    int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>temp=grid;
        vector<vector<int>>vis(n,vector<int>(m,0));
        vector<vector<int>>ans(n, vector<int>(m, 0));
        queue<pair<pair<int,int>,int>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(temp[i][j]==1){
                    vis[i][j]=1;
                    ans[i][j]=0;
                    q.push({{i,j},0});
                }
            }
        }
        int delrow[] = {-1,0,+1,0};
        int delcol[] = {0,+1,0,-1};
        while(!q.empty()){
            int row = q.front().first.first;
            int col = q.front().first.second;
            int dis = q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int nrow = row+delrow[i];
                int ncol = col+delcol[i];
                int dis2 = dis+abs(nrow-row)+abs(ncol-col);

                if(nrow>=0 && ncol>=0 && nrow<n && ncol<m && !vis[nrow][ncol]&&temp[nrow][ncol]==0){
                     vis[nrow][ncol]=1;
                     ans[nrow][ncol]=dis2;
                     q.push({{nrow,ncol},dis2});
                }
            }
        }
        return ans;
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
		vector<vector<int>> ans = obj.nearest(grid);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends