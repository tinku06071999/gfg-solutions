//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    vector<int> reverseSpiral(int R, int C, vector<vector<int>>&a)  {
        // code here
        vector<int>v;
        	int s_row = 0, s_col = 0;
 		int e_row = R-1, e_col = C-1;
 		int count = 0;
 		int total = R*C;
 		while(count<total){
 		    for(int i=s_col;i<=e_col && count<total ;i++){
 		        v.push_back(a[s_row][i]);
 		        count++;   
 		       
 		    }
 		 
 		    s_row++;
 		    
 		    for(int i=s_row;i<=e_row&&count<total;i++){
 		        v.push_back(a[i][e_col]);
 		        count++;
 		        
 		    }
 		
 		    e_col--;
 		    
 		    for(int i = e_col;i>=s_col&&count<total;i--){
 		        v.push_back( a[e_row][i]);
 		        count++;
 		    }
 	
 		    e_row--;
 	
 		    for( int i=e_row;i>=s_row&&count<total;i--){
 		        v.push_back(a[i][s_col]);
 		        count++;
 		    }
 	
 		    s_col++;
 		}
 		reverse(v.begin(),v.end());
 		return v;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int R, C;
        cin>>R>>C;
        vector<vector<int>> a(R, vector<int>(C, 0));
        for(int i = 0;i < R*C;i++)
            cin>>a[i/C][i%C];
        Solution ob;
        vector<int>ans=ob.reverseSpiral(R,C,a);
        for(int i=0;i<ans.size();i++)cout<<ans[i]<<" ";
            cout<<endl;
    }
    return 0;
}

// } Driver Code Ends