//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int sumOfNaturals(int n) {
        // code here
        int sum=0;
        n = n%1000000007;
        long long int  k = (n+1)%1000000007;
        long long int upper = (n*k)%1000000007;
        long long int  ans = ((upper%1000000007)/2)%1000000007;
        return ans%1000000007;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        
        cin>>n;

        Solution ob;
        cout << ob.sumOfNaturals(n) << endl;
    }
    return 0;
}
// } Driver Code Ends