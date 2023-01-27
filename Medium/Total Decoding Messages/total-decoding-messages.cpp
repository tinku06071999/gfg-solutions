//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
        int mod = 1e9+7; 

    int solve(string str , int n , vector<int>&dp){

            int count = 0 ; 

     // base case 

     if(n==0  || n == 1 ){

         return 1; 

     }

     if(dp[n]!=-1){

         return dp[n]; 

     }

     // non pairs numbers  

     if(str[n-1]>='1'){

         count = count + (solve(str , n-1 , dp)%mod); 

     }

     // counting for pairs in string 

     if(str[n-2]=='1' || str[n-2]=='2' && str[n-1]<='6'){

         count = (count + solve(str , n-2 , dp )%mod)%mod; 

     }

     return dp[n] = count%mod ; 

    }
	public:
		int CountWays(string str){
		       int n = str.size(); 

     vector<int>dp(n+1 , -1); 

     return solve(str,n,dp); 
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution obj;
		int ans = obj.CountWays(str);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends