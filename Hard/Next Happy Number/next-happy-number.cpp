//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std;

// } Driver Code Ends
class Solution{
public:
  bool solve(int n){
      if(n>=2 && n<=9 && n!=7)return false;
      if(n==1 || n==7)return true;
      int sum=0;
      while(n){
          sum+=(n%10)*(n%10);
          n/=10;
      }
      return solve(sum);
  }
    int nextHappy(int N){
        // code here
        int i = N+1;
        while(i){
            if(solve(i))return i;
            i++;
        }
        return 0;
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
        cout << ob.nextHappy(N) << endl;
    }
    return 0; 
}
// } Driver Code Ends