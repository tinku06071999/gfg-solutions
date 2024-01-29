//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
        int solve(int i1,int i2,int i3,int n1, int n2, int n3, string&A, string&B, string&C,vector<vector<vector<int>>>&dp){
            // if(i1<0 || i2<=0 )return 0;
            if(i1 >= n1 || i2 >= n2 || i3 >= n3){
               return 0;
            }
            int take =0,nottake =0;
            if(dp[i1][i2][i3] != -1)return dp[i1][i2][i3];
            if(A[i1] == B[i2] && B[i2] == C[i3]){
             take = 1 + solve(i1 + 1,i2 + 1,i3 + 1,n1,n2,n3,A,B,C,dp);
            }
            nottake = max(solve(i1 + 1,i2,i3,n1,n2,n3,A,B,C,dp) ,max(solve(i1,i2 + 1,i3,n1,n2,n3,A,B,C,dp), solve(i1,i2,i3 + 1,n1,n2,n3,A,B,C,dp)));
            
            return dp[i1][i2][i3] = max(take,nottake);
        }
        
        int LCSof3 (string A, string B, string C, int n1, int n2, int n3)
        {
           vector<vector<vector<int>>>dp(n1,vector<vector<int>>(n2,vector<int>(n3,-1)));
            return solve(0,0,0,n1,n2,n3,A,B,C,dp);
        }
};


//{ Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n1, n2, n3; cin >> n1 >> n2 >> n3;
        string A, B, C; cin >> A >> B >> C;
        Solution obj;
        cout << obj.LCSof3 (A, B, C, n1, n2, n3) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends