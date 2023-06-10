//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
#define ll long long

// } Driver Code Ends
class Solution
{
    public:
        void Rearrange(int arr[], int n)
        {
            // Your code goes here
            int i=0;
            int j=1;
            vector<int>v1;
            vector<int>v2;
           
            for(int i =0;i<n;i++){
                if(arr[i]<0)v1.push_back(arr[i]);
                else v2.push_back(arr[i]);
            }
            int k=0;
            
            for(int i=0;i<v1.size();i++){
                arr[k] = v1[i];
                k++;
            }
            // for(int i=0;i<v1.size();i++)cout<<v2[i]<<" "<<endl;
            // k++;
            for(int j =0;j<v2.size() && k<n;j++){
                arr[k] = v2[j];
                k++;
            }
        }
};

//{ Driver Code Starts.
void Rearrange(int arr[], int n);

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
        cin>>arr[i];
        long long j=0;
        Solution ob;
        ob.Rearrange(arr, n);
      
        for (int i = 0; i < n; i++) 
            cout << arr[i] << " "; 
        cout << endl;  
    }
    return 0; 
} 
// } Driver Code Ends