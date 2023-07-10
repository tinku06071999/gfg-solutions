//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
#define MAX 1000

// } Driver Code Ends
class Solution
{
    public:
    /*You are required to complete this method*/
    int findK(int a[MAX][MAX],int n,int m,int k)
    {
 		// Your code goes here
 		int s_row = 0, s_col = 0;
 		int e_row=n-1,e_col=m-1;
 		int count=0;
//  		int total = n*m;
 		while(count<=k){
 		    for(int i=s_col;i<=e_col && count<=k ;i++){
 	          //  cout<<a[s_row][i]<<" ";
 		        count++;   
 		        if(count==k)return a[s_row][i];
 		    }
 		 //   cout<<endl;
 		    s_row++;
 		    for(int i=s_row;i<=e_row&&count<=k;i++){
 		         //cout<<a[i][e_col]<<" ";
 		        count++;
 		        if(count==k)return a[i][e_col];
 		    }
 		 //   cout<<endl;
 		    e_col--;
 		    for(int i = e_col;i>=s_col&&count<=k;i--){
 		         //cout<<a[e_row][i]<<" ";
 		        count++;
 		        if(count==k)return a[e_row][i];
 		    }
 		 //   cout<<endl;
 		    e_row--;
 		 //   int i = e_row;
 		    for( int i=e_row;i>=s_row&&count<=k;i--){
 		         //cout<<a[i][s_col]<<" ";
 		        count++;
 		        if(count==k)return a[i][s_col];
 		    }
 		 //   cout<<endl;
 		    s_col++;
 		 //   if(count==k)return a[s_col][i];
 		}
 		return 0;
    }
};





//{ Driver Code Starts.
int main()
{
    int T;
    cin>>T;
  
    while(T--)
    {
        int n,m;
        int k=0;
        //cin>>k;
        cin>>n>>m>>k;
        int a[MAX][MAX];
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cin>>a[i][j];
            }
        }
        Solution ob;
        cout<<ob.findK(a,n,m,k)<<endl;
        
       
    }
}
// } Driver Code Ends