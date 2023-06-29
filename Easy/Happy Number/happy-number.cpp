//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std;

// } Driver Code Ends
class Solution{
public:
  bool solve(int n){
      if(n>=2 && n<=9 && n!=7)return 0;
      if(n==1 || n==7)return 1;
      int sum=0;
      while(n){
          sum += (n%10)*(n%10);
          n /=10;
      }
      return solve(sum);
  }
    int isHappy(int N){
        // code here
        return solve(N);
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        Solution ob;
        cout << ob.isHappy(N) << endl;
    }
    return 0; 
}
// } Driver Code Ends