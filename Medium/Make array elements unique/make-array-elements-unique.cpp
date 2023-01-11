//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    long long int minIncrements(vector<int> arr, int N) {
        // Code here
        // sort(arr.begin(),arr.end());
        // long long count = 0;
        //  if(N==0)return 0;
        //  for(int i=1;i<N;i++){
        //      if(arr[i-1]>=arr[i]){
        //          count += arr[i-1]-arr[i]+1;
        //          arr[i]=arr[i-1]+1;
        //  }
        // }
        // return count;
         //     sort(arr.begin(),arr.end());
    //     int count =0;
    //     int i = 0;
    //     while(i<N){
    //         if(arr[i]==arr[i+1]){
    //             arr[i+1]=arr[i+1]+1;
    //             count++;
    //             // i++;
    //         }
    //         else i++;
    //     }
    //     return count;
    // }
        // Code here
        sort(arr.begin(),arr.end());
        
        int prev = arr[0];
        int ans = 0;
        for(int i=1; i<N; i++)
        {
            if(arr[i]>prev) prev = arr[i];
            else
            {
                ans+= (prev + 1 - arr[i]);
                prev++;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.minIncrements(arr, N) << endl;
    }
}
// } Driver Code Ends