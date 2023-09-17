//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    bool solve(int i, int a[], int n){
        if(i==n-1)return true;
        for(int k = i+1; k<= a[i]+i;k++){
            if(solve(k,a,n))return true;
        }
        return false;
    }
    int canReach(int a[], int n) {
        // code here
        return solve(0,a,n);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin>>N;
        
        int A[N];
        
        for(int i=0; i<N; i++)
            cin>>A[i];

        Solution ob;
        cout << ob.canReach(A,N) << endl;
    }
    return 0;
}
// } Driver Code Ends