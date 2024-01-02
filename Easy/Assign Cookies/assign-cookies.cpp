//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int maxChildren(int N, int M, vector<int> &greed, vector<int> &sz) {
        // code here
        sort(greed.begin(),greed.end());
        sort(sz.begin(),sz.end());
        int count=0;
        int childIdx = N-1;
        int cookieIdx = M-1;
        
        while(childIdx >=0 && cookieIdx >=0 ){
            if(greed[childIdx] <= sz[cookieIdx]){
                count++;
                childIdx--;
                cookieIdx--;
            }
            else{
                childIdx--;
            }
        }
        return count;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M;
        cin >> N >> M;

        vector<int> greed(N), sz(M);
        for (int i = 0; i < N; i++) {
            cin >> greed[i];
        }
        for (int i = 0; i < M; i++) {
            cin >> sz[i];
        }
        Solution obj;
        cout << obj.maxChildren(N, M, greed, sz) << endl;
    }
    return 0;
}
// } Driver Code Ends