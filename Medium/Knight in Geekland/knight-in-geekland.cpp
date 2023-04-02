//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
   int dx[8] = {-1, -2, -2, -1, 1, 2, 2, 1};
    int dy[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
    int knightInGeekland(int start_x,int start_y,vector<vector<int>> &arr){
            // Code here
        int n = arr.size();  // number of rows in the arr
        int m = arr[0].size();  // number of columns in the arr
        
        bool visited[n][m];  // 2D boolean array to keep track of visited cells
        memset(visited, false, sizeof(visited));
        queue<pair<int, int>> q;  // Queue to perform BFS
        q.push(make_pair(start_x, start_y));  // Add starting position to queue
        visited[start_x][start_y] = true;  // Mark starting position as visited
        
        int points[1001];  // Array to store the sum of points collected at each level
        memset(points, 0, sizeof(points));
        int steps = 0;  // Variable to keep track of the current level
        
        // Perform BFS traversal
        while (!q.empty()) {
            int qSize = q.size(); 
            while (qSize-- > 0) {
                pair<int, int> curr = q.front();  // Get the first element from the queue
                q.pop();
                int x = curr.first;
                int y = curr.second;
                
                points[steps] += arr[x][y];  // Add the points to the corresponding level
                
                // Traverse through all 8 possible moves for the knight
                for (int k = 0; k < 8; k++) {
                    int currX = x + dx[k];  // New x coordinate
                    int currY = y + dy[k];  // New y coordinate
                    
                    // Check if the new coordinates are valid and not visited
                    if (currX < 0 || currY < 0 || currX >= n || currY >= m || visited[currX][currY]) {
                        continue;
                    }
                    
                    visited[currX][currY] = true;  // Mark the new coordinates as visited
                    q.push(make_pair(currX, currY));  // Add the new coordinates to the queue
                }
            }
            steps++;  // Increment the level
        }
        
        int ans = 0;  // Variable to store the answer
        int maxi = INT_MIN;  // Maximum value initialized to a very small value
        for (int i = 0; i <= 1000; i++) {
            int curr = i;  // Current level
            int totalpoints = 0;  // Total points collected
            
            // Calculate the total points collected for every jump of i positions
            while (curr <= 1000) {
                if (points[curr] == 0) {
                    break;
                }
                totalpoints += points[curr];
                curr += points[curr];
            }
            points[i] = totalpoints;  // Update the points array with the total points collected
            if (points[i] > maxi) {  // Check if the total points collected is greater than the current maximum
                maxi = points[i];  // Update the maximum value
                ans = i;  // Update the answer
            }
        }
        return ans;  // Return the answer
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m,start_x,start_y;
        cin>>n>>m>>start_x>>start_y;
        vector<vector<int>> arr(n,vector<int>(m));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>arr[i][j];
            }
        }
        Solution ob;
        cout<<ob.knightInGeekland(start_x,start_y,arr)<<endl;
    }
}
// } Driver Code Ends