//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:

    bool solve(int sr, int sc, int k,vector<vector<char>>& board, string word, int n, int m ){
         if(k == word.length())return true;
         
         if(sr < 0 || sr == n || sc < 0 || sc == m || board[sr][sc] != word[k])return 0;
         
         char c = board[sr][sc];
         board[sr][sc] = '#';
         
        //  bool up = solve(sr-1, sc, k+1, board, word, n,m);
        //  bool down = solve(sr+1, sc, k+1, board, word, n,m);
        //  bool left = solve(sr, sc-1, k+1, board, word, n,m);
        //  bool right = solve(sr, sc+1, k+1, board, word, n,m);
         
        //  board[sr][sc] = c;
         
        //  return up || down || left ||right;
        
        
         
        
         bool up = solve(sr-1, sc, k+1, board, word, n, m);
         bool down = solve(sr+1, sc, k+1, board, word, n, m);
         bool left = solve(sr, sc-1, k+1, board, word, n, m);
         bool right = solve(sr, sc+1, k+1, board, word, n, m);

         board[sr][sc] = c;

         return up||down || left || right;
    }
    
    bool isWordExist(vector<vector<char>>& board, string word) {
        // Code here
        // int n = board.size();
        // int m = board[0].size();
        
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<m;j++){
        //         if(board[i][j] == word[0]){
        //             if(solve(i,j,0,board,word,n,m))
        //             return true;
        //         }
        //     }
        // }
        // return false;
        
         int n = board.size();
        int m = board[0].size();
        for(int i=0;i<n;i++){
            for(int j =0;j<m;j++){
                if(board[i][j] == word[0] ){
                    if(solve(i,j,0,board, word, n,m))
                    return true;
                }
            }
        }
       return false;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>board(n, vector<char>(m, '*'));
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				cin >> board[i][j];
		string word;
		cin >> word;
		Solution obj;
		bool ans = obj.isWordExist(board, word);
		if(ans)
			cout << "1\n";
		else cout << "0\n";
	}
	return 0;
}
// } Driver Code Ends