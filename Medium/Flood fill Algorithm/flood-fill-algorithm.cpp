//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
//     void bfs(int row, int col, vector<vector<int>>&vis,vector<vector<int>>&image, int n ,int m,int prevcolor,int color){
//       vis[row][col]=1;
//       queue<pair<int,int>>q;
//       q.push({row,col});
//       while(!q.empty()){
//           int row = q.front().first;
//           int col = q.front().second;
//           q.pop();
//             // if(image[row][col]) 
//             if(image[row][col]==prevcolor){
//                   image[row][col]=color;
//             }
//             if(row-1>=0 && !vis[row-1][col]&& image[row-1][col]==prevcolor){
//                  vis[row-1][col]=1;
//                   q.push({row-1,col});
//                   image[row-1][col]=color;
//             }
//              if(col+1<m && !vis[row][col+1]&& image[row][col+1]==prevcolor){
//                  vis[row][col+1]=1;
//                   q.push({row,col+1});
//                   image[row][col+1]=color;
//             }
//             if(row+1<n && !vis[row+1][col]&& image[row+1][col]==prevcolor){
//                  vis[row+1][col]=1;
//                   q.push({row+1,col});
//                   image[row+1][col]=color;
//             }
//             if(col-1>=0 && !vis[row][col-1]&& image[row][col-1]==prevcolor){
//                  vis[row][col-1]=1;
//                   q.push({row,col-1});
//                   image[row][col-1]=color;
//             }
           
//       }
//   }
  void dfs(int sr,int sc, vector<vector<int>>& ans,vector<vector<int>>& image,int delrow[],int delcol[],int inicolor, int color){
      ans[sr][sc] = color;
         int n=image.size();
        int m = image[0].size();
      for(int i=0;i<4;i++){
          int nrow = sr+delrow[i];
          int ncol = sc+delcol[i];
          if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && image[nrow][ncol]==inicolor && ans[nrow][ncol]!=color){
              dfs(nrow,ncol,ans,image,delrow,delcol,inicolor,color);
          }
      }

  }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        // int n=image.size();
        // int m = image[0].size();
        // vector<vector<int>>vis(n,vector<int>(m,0));
        //      int prevcolor = image[sr][sc];
        //         bfs(sr,sc,vis,image,n,m,prevcolor,color);
        // return image;
        
        
        // using dfs
         vector<vector<int>>ans = image;
        int inicolor = image[sr][sc];
        int delrow[] = {-1,0,1,0};
        int delcol[] = {0,+1,0,-1};
       
        dfs(sr,sc,ans,image,delrow,delcol,inicolor,color);
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
		vector<vector<int>>image(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> image[i][j];
		}
		int sr, sc, newColor;
		cin >> sr >> sc >> newColor;
		Solution obj;
		vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
		for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends