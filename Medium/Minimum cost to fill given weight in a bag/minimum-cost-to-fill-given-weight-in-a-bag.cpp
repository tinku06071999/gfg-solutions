//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Array {
  public:
    template <class T>
    static void input(vector<T> &A, int n) {
        for (int i = 0; i < n; i++) {
            scanf("%d ", &A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A) {
        for (int i = 0; i < A.size(); i++) {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends

class Solution {
  public:
    int solve(int idx, vector<int>&cost, int w, int n, vector<vector<int>>&dp){
        if (w == 0) return 0;
        
        if (idx == n || w < 0) return INT_MAX; 
        
        if(dp[idx][w] != -1)return dp[idx][w];
        
        if (cost[idx] == -1) dp[idx][w] =  solve(idx + 1, cost, w, n,dp);

    int take = INT_MAX;
    
    if (idx + 1 <= w) {
        int sub_res = solve(idx, cost, w - (idx + 1), n, dp);         
          if (sub_res != INT_MAX) {
            take = cost[idx] + sub_res;
        }
    }
    int notTake = solve(idx + 1, cost, w, n, dp); 

    return dp[idx][w] = min(take, notTake);
    }
    int minimumCost(int n, int w, vector<int> &cost) {
        // code here
        vector<vector<int>>dp(n, vector<int>(w+1, -1));
        int res =  solve(0,cost, w,n, dp);
        
        return (res == INT_MAX)? -1: res;
    }
    
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int n;
        scanf("%d", &n);

        int w;
        scanf("%d", &w);

        vector<int> cost(n);
        Array::input(cost, n);

        Solution obj;
        int res = obj.minimumCost(n, w, cost);

        cout << res << endl;
    }
}

// } Driver Code Ends