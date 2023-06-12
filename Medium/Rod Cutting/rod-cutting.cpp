//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
  public:
    int cutRod(int price[], int n) {
        //code here
        int low ,high;
       for(int i=0;i<n;i++){
           
           low =0;
           high=i-1;
           while(low<=high){
               price[i] = max(price[i], price[low] + price[high]);
               low++;
               high--;               
           }
           
       }
       return price[n-1];
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends