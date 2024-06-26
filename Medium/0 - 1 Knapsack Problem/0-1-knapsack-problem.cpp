//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    
    int solve(int idx, int w, int wt[], int val[], vector<vector<int>>&dp){
        if(idx ==0){
            if(wt[idx] <= w)return val[idx];
            else return 0;
        }
        
        if(dp[idx][w] != -1)return dp[idx][w];
        
        int take = 0;
        
        if(wt[idx] <= w){
            take = val[idx] + solve(idx-1, w - wt[idx], wt, val, dp);
        }
        int not_take = solve(idx-1, w, wt, val, dp);
        
        return dp[idx][w] = max(take, not_take);
    }
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       // Your code here
       vector<vector<int>>dp(n, vector<int>(W+1, -1));
       return solve(n-1, W, wt, val,dp);
    }
};

//{ Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends