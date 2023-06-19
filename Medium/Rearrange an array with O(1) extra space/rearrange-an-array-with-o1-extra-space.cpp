//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
    

class Solution{
    public:
    // arr: input array
    // n: size of array
    //Function to rearrange an array so that arr[i] becomes arr[arr[i]]
    //with O(1) extra space.
    void arrange(long long arr[], int n) {
        // Your code here
        // if(n==2){
        //     int tmp = arr[0];
        //     arr[0] = arr[arr[0]];
        //     arr[1] = arr[arr[1]];
        // }
        // int last_idx=0;
        // int last_ele =arr[0];
        // int num=0;
        // arr[0] = arr[last_ele];
        // int i=0;
        // while(n){
        //     if(arr[i] == last_idx){
        //         num = arr[i];
        //         arr[i] = last_ele;
        //         last_idx = i;
        //         last_ele = num;
        //         n--;
        //         i=0;
        //     }
        //     else i++;
          for(int i = 0; i<n; i++) {
            arr[i] = arr[i] + (arr[arr[i]]%n)*n;
        }
        for(int i = 0; i<n; i++) {
            arr[i] = arr[i]/n;
        }
        return;
    }
};


//{ Driver Code Starts.

int main(){
    
    int t;
    //testcases
    cin>>t;
    while(t--){
        
        int n;
        //size of array
        cin>>n;
        long long A[n];
        
        //adding elements to the array
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        Solution ob;
        //calling arrange() function
        ob.arrange(A, n);
        
        //printing the elements 
        for(int i=0;i<n;i++){
            cout << A[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends