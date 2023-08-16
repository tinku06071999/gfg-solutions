//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{  
private:
    bool solve(int idx,int sum , vector<int>arr,vector<vector<int>>&dp){
        if(sum==0)return true;
        if(idx==0)return arr[0]==sum;
        if(dp[idx][sum]!=-1)return dp[idx][sum];
        // not take
        bool notTake = solve(idx-1,sum,arr,dp);
         
        bool take = false;
        if(arr[idx]<=sum)
        take = solve(idx-1,sum-arr[idx],arr,dp);
        
        return dp[idx][sum] = take||notTake;
    }
public:
    bool isSubsetSum(vector<int>arr, int sum){
        // code here 
        int n = arr.size();
        vector<vector<int>>dp(n,vector<int>(sum+1,-1));
        return solve(n-1,sum,arr,dp);
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 

// } Driver Code Ends