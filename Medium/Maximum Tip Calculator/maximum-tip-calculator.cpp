//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Array {
  public:
    template <class T>
    static void input(vector<T> &a, int n) {
        for (int i = 0; i < n; i++) {
            scanf("%d ", &a[i]);
        }
    }

    template <class T>
    static void print(vector<T> &a) {
        for (int i = 0; i < a.size(); i++) {
            cout << a[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends

class Solution {
  public:
   long long solve(int n, int x, int y,vector<int> &arr, vector<int> &brr, vector<vector<vector<int>>>&dp ){
    if(n==0)return 0;
    
    if(y==0)return arr[n-1] + solve(n-1,x-1, y, arr, brr, dp);
    if(x==0) return  brr[n-1] + solve(n-1, x, y-1, arr, brr, dp);
  
    if(dp[n][x][y] != -1)return dp[n][x][y];
    
      int ans = max(
                    arr[n-1] + solve(n-1, x-1, y , arr, brr, dp),
                    brr[n-1] + solve(n-1, x, y-1, arr, brr, dp)
                  );
    return dp[n][x][y] = ans;
    
     }
    long long maxTip(int n, int x, int y, vector<int> &arr, vector<int> &brr) {
        // code here
        // vector<vector<vector<int>>>dp(n+1, vector<vector<int>>(x+1, vector<int>(y+1, -1))) ;
        // return solve(n, x, y, arr, brr, dp);
        
        long long sum =0;
        for(int i=0;i<n;i++){
            brr[i] = brr[i] - arr[i];
            sum += arr[i];
        }
        sort(brr.begin(), brr.end());
        
        int i =0, c =0;
        
        while(brr[i] <= 0 && i < x){
            c++;
            i++;
        }
        i = 0;
        
        while(i< y && c < n){
            sum +=brr[n-1-i];
            c++;
            i++;
        }
        return sum;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int n;
        scanf("%d", &n);

        int x;
        scanf("%d", &x);

        int y;
        scanf("%d", &y);

        vector<int> arr(n);
        Array::input(arr, n);

        vector<int> brr(n);
        Array::input(brr, n);

        Solution obj;
        long long res = obj.maxTip(n, x, y, arr, brr);

        cout << res << endl;
    }
}

// } Driver Code Ends