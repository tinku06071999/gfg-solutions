//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int minRepeats(string A, string B) {
        // code here 
        int n=A.size();
        int m=B.size();
        int i=0;
        int j=0;
        int cnt=1;
       
        while(i < n and j < m){
            if(A[i]==B[j]){
                i++;
                j++;
                break;
            }
            
            i++;
        }
        
        
        while(j < m){
            if(A[i]==B[j]){
            if(i==0){
                cnt++;
            }
            i=(i+1)%n;
            j++;
            }
            else{
                return -1;
            }
                
        }
        
        return cnt;
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ",&t);
    while (t--) {
        string A,B;
        getline(cin,A);
        getline(cin,B);

        Solution ob;
        cout << ob.minRepeats(A,B) << endl;
    }
    return 0;
}
// } Driver Code Ends