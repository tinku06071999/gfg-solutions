//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:

    // Note that the size of the array is n-1
    int missingNumber(int n, vector<int>& arr) {

        // Your code goes here
        // int s1 = (n*(n+1))/2;
        // int s2 = 0;
        int n2 = arr.size();
        // for(int i=0;i<n2;i++)s2 += arr[i];
        
        // return s1-s2;
        
        int x1 = arr[0];
        int x2 = 1;
        
        for(int i =1; i< n2; i++){
            x1 ^= arr[i];
        }
        for(int i = 2; i<=n; i++){
            x2 ^= i;
        }
        return x1 ^ x2;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector<int> arr(n - 1);
        for (int i = 0; i < n - 1; ++i)
            cin >> arr[i];
        Solution obj;
        cout << obj.missingNumber(n, arr) << "\n";
    }
    return 0;
}
// } Driver Code Ends