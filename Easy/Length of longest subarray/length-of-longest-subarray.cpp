//{ Driver Code Starts
#include <iostream>
using namespace std;

long long int longestSubarry(long long int *arr, long long int n);

// Driver code
int main() {
    long long int t, i;
    cin >> t;
    while (t--) {
        long long int n;
        cin >> n;
        long long int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        cout << longestSubarry(arr, n) << endl;
    }
    return 0;
}

// } Driver Code Ends


long long int longestSubarry(long long int A[], long long int N) {
    int i=0;
    int j=0;
    int maxi =0;
    int count=0;
    while(j<N){
        if(A[j]>=0){
            j++;
            count++;
        }
        else if(A[j]<0){
            maxi = max(maxi,count);
            count=0;
            j++;
            i=j;
        }
    }
    maxi = max(maxi,count);
    return maxi;
}