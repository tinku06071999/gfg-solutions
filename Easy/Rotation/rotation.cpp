//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	int findKRotation(int arr[], int n) {
	    // code here
    int s =0;
    int e = n-1;
    int mid = (s+e)/2;

    while(s<e){
        if(arr[mid]>=arr[0])s=mid+1;
        else e = mid;
        mid = (s+e)/2;
    }   
    if(s==e){
        if(arr[e]>=arr[0])return 0;
    }
    return s;
	}

};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findKRotation(a, n);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends