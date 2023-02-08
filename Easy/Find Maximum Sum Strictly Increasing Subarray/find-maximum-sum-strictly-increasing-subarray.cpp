//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution{
    public:
    int maxsum_SIS(int arr[] , int n)
    {
        // Your code goes here   
        int maxi =0;
        int sum =arr[0];
        if(n==1)return arr[0];
     
        for(int i=1;i<=n-1;i++){
         
            if(arr[i] <=arr[i-1]){
                maxi = max(maxi,sum);
                sum = arr[i];
                
            }
            else{
                sum+=arr[i];
                maxi = max(maxi,sum);
            }
            
        }
        return maxi;
    }
};

//{ Driver Code Starts.
// Driver code
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
    	int n;
    	cin>>n;
    	int a[n];
    	for(int i=0;i<n;i++)
    	cin>>a[i];
    	Solution ob;
    	cout<<ob.maxsum_SIS(a, n)<<endl;
    }
}

// } Driver Code Ends