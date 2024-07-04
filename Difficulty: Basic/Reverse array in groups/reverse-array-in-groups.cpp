//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
  
   void reverse(vector<long long int> &arr, int strt, int end){
       
       while(strt < end ){
           swap(arr[strt], arr[end]);
           strt++;
           end--;
       }
       return;
   }
    void reverseInGroups(vector<long long int> &arr, int k) {
        int n = arr.size();
        for(int i=0;i<n;i += k){
            int end = min(i+k-1, n-1);
            reverse(arr, i, end);
        }
        return;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int k;
        cin >> k;
        vector<long long int> arr;
        string input;
        cin.ignore();
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution ob;
        ob.reverseInGroups(arr, k);
        for (long long i = 0; i < arr.size(); i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends