//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++
class Solution
{
public:
   bool solve(int idx){
       for(int i=1;i<=idx;i++){
           if(idx % i ==0)return true;
           
       }
   }
    long long sumOfDivisors(int N)
    {
        // Write Your Code here
        long long ans=0;
        // return solve(1, ans,N);
        for(int i=1;i<=N;i++){
            ans += i * (N/i);
        }
        return ans;
       
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        Solution ob;
        long long ans  = ob.sumOfDivisors(N);
        cout<<ans<<endl;
    }
    return 0;
}
// } Driver Code Ends