//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	// Converts arr[0..n-1] to reduced form.
	void convert(int arr[], int n) {
	   // code here
	    vector<int>v;
	    for(int i=0;i<n;i++){
	        v.push_back(arr[i]);
	    }
	   sort(v.begin(),v.end());
	   map<int,int>mp;
	   for(int i=0;i<v.size();i++){
	       mp[v[i]]=i;
	   }
	   for(int i=0;i<n;i++){
	       if(mp.find(arr[i])!=mp.end()){
	           auto temp = mp.find(arr[i]);
	           arr[i] = temp->second;
	       }
	   }
	
	}

};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        ob.convert(arr, n);
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends