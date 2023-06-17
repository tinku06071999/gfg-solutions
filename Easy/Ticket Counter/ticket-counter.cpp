//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int distributeTicket(int N, int K) {
        // code here
        int count =0;
        int i=1,j=N;
        while(i<j){
            int l=0;
            if(count%2==0){
                while(l<K){
                    i++;
                    l++;
                    
                }
                count++;
            }
            else if(count%2!=0){
                while(l<K){
                    j--;
                    l++;
                }
                count++;
            }
        }
        if(count%2==0)return i;
        return j;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int N;
        scanf("%d",&N);
        
        
        int K;
        scanf("%d",&K);
        
        Solution obj;
        int res = obj.distributeTicket(N, K);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends