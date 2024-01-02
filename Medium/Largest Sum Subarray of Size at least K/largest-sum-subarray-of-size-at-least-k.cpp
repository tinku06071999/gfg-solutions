//{ Driver Code Starts
// C++ program to find largest subarray sum with
// at-least k elements in it.
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:    
    long long int maxSumWithK(long long int a[], long long int n, long long int k) 
    {
         long long int ans = INT_MIN;
        long long int sum =0;
        for(int i=0;i<k;i++){
            sum += a[i];
        }
        if(k==n)return sum;
         
        int prevElemSum = 0;
        ans = sum;
        
        int i=0;
        
        int j=k;
        while(j<n){ 
               sum +=a[j];
               ans = max(sum,ans);
               prevElemSum = prevElemSum + a[i++];
           if(prevElemSum  < 0){
               sum -= prevElemSum ;
               prevElemSum = 0;
               ans = max(sum,ans);
           }
           j++;
        }
        return ans;
    }
};

//{ Driver Code Starts.

// Driver code
int main() {
    long long int t;
    cin >> t;
    while (t--) {
        long long int n, k, i;
        cin >> n;
        long long int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        cin >> k;
        Solution ob;
        cout << ob.maxSumWithK(a, n, k) << endl;
    }
    return 0;
}

// } Driver Code Ends