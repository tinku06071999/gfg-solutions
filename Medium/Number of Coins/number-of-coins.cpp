//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	int solve(int coins[],int v,int idx,vector<vector<int>> &dp){
	   // if(idx==0)return 0;
	   // if(idx<0)return INT_MAX;
	    if(v<0 || idx <0)return 1e8;
	    if(v==0)return 0;
	    if(dp[idx][v] !=-1)return dp[idx][v];
	    int pick = 1+solve(coins, v-coins[idx],idx,dp);
	    int not_pick = solve(coins,v,idx-1,dp);
	    return dp[idx][v] = min(pick,not_pick);
	}
	int minCoins(int coins[], int M, int V) 
	{ 
	    // Your code goes here
	   // sort(coins,coins+M);
	   vector<vector<int>>dp(M+1,vector<int>(V+1,-1));
	   if(solve(coins,V,M-1,dp)>=1e8)return -1;
	    return solve(coins,V,M-1,dp);
	} 
	  
};

//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int v, m;
        cin >> v >> m;

        int coins[m];
        for(int i = 0; i < m; i++)
        	cin >> coins[i];

      
	    Solution ob;
	    cout << ob.minCoins(coins, m, v) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends