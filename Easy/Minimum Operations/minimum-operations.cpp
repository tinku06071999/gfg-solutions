//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
  public:
    int solve(int idx, int n){
        if(idx==n)return 1;
        if(idx > n)return 0;
        // int db =0;
        int add = 1 + solve(idx + 1, n);
        // if(idx <= n/2) 
        int db = 1 + solve(2 * idx, n);
        return min(add,db);
    }
    int minOperation(int n)
    {
        //code here.
        // return solve(0,n);
        if(n==2)return 2;
        if(n==1)return 1;
        if(n % 2 == 0)return 1 + minOperation(n/2);
        else return 2 + minOperation((n-1)/2);
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	    {
	        int n;
	        cin>>n;
	        Solution ob;
	        cout<<ob.minOperation(n)<<endl;
	    }
}
// } Driver Code Ends