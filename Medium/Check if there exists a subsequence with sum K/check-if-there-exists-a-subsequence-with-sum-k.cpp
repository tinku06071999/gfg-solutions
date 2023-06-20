//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    bool solve(int idx,vector<int>&arr,int sum,int k){
        if(idx==arr.size() ){
            if(sum==k)return true;
            return false;
            
        }
         if(sum>k)return false;
      
        sum +=arr[idx];
         if(solve(idx+1,arr,sum,k)){
            return true;
        }
        sum=sum-arr[idx];
         if(solve(idx+1,arr,sum,k)){
            return true;
        }
        return false;
    }
    bool checkSubsequenceSum(int n, vector<int>& arr, int k) {

        return solve(0,arr,0,k);
      
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--){
        int n,k; cin>>n>>k;
        vector<int> arr;
        
        for(int i=0; i<n; ++i){
            int x; cin>>x;
            arr.push_back(x);
        }
        
        Solution obj;
        bool ans = obj.checkSubsequenceSum(n, arr, k);
        cout<<( ans ? "Yes" : "No")<<"\n";
    }
    return 0;
}
// } Driver Code Ends