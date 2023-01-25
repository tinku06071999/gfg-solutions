//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    int minOperation(string s) {
        // code here
        int le=0,n=s.length();

        for(int j=2;j<=n/2;j++){

            int i=0,flag=0,temp=j;

            while(i!=j){

                if(s[i]!=s[temp]){

                    flag=1;

                    break;

                }

                i++;

                temp++;

            }

            if(!flag){

                le=max(le,j);

            }

        }

        if(le)

        return n-le+1;

        return n;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.minOperation(s) << "\n";
    }
    return 0;
}

// } Driver Code Ends