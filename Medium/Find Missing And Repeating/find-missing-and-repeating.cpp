//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution{
public:
    vector<int> findTwoElement(vector<int> A, int n) {
        // code here
       vector<int>count(n);
       for(int i=0;i<n;i++){
           count[A[i]-1]++;
       }
       int rep =0;
       int missing =0;
       for(int i=0;i<count.size();i++){
           if(count[i] == 0){
               missing = i+1;
           }else if(count[i] > 1){
               rep = i+1;
           }
       }
       return {rep, missing};
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}
// } Driver Code Ends