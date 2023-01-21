//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  int to_binary(int n){
      string s="";
      while(n>0){
          s+='0'+n%2;
          n=n/2;
      }
      int sum =0;
      for(int i=0;i<s.size();i++){
          if(s[i]=='1'){
              sum++;
          }
      }
      return sum;
  }
    int minVal(int a, int b) {
       int x = 0;
        int cnt = __builtin_popcount(b);
        for(int i=31;i>=0;i--){
            
            if((1<<i)&a){
                if(cnt>0){
                    cnt--;
                    x |= (1<<i);
                }
            }else{
                if(i<cnt){
                   x |= (1<<i);
                   cnt--;
                }
            }
        }
        return x;
    } 
    
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;

        Solution ob;
        cout << ob.minVal(a, b);

        cout << "\n";
    }

    return 0;
}
// } Driver Code Ends