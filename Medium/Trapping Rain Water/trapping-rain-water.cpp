//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution{

    // Function to find the trapped water between the blocks.
    public:
    long long trappingWater(int arr[], int n){
        // code here
        int prefix[n];
        int suffix[n];
        prefix[0] = arr[0];
        suffix[n-1] = arr[n-1];
        for(int i=1;i<n;i++){
            prefix[i] = max(prefix[i-1],arr[i]);
        }
        for(int i = n-2;i>=0;i--)suffix[i] = max(suffix[i+1],arr[i]);
        
        long long ans=0;
        for(int i=0;i<n;i++){
            ans += min(prefix[i],suffix[i]) - arr[i];
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        
        int a[n];
        
        //adding elements to the array
        for(int i =0;i<n;i++){
            cin >> a[i];            
        }
        Solution obj;
        //calling trappingWater() function
        cout << obj.trappingWater(a, n) << endl;
        
    }
    
    return 0;
}
// } Driver Code Ends