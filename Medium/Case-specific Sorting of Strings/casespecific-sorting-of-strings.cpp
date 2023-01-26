//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    //Function to perform case-specific sorting of strings.
    string caseSort(string str, int n)
    {
        // your code here
        vector<char>low;
        vector<char>up;
        for(int i=0;i<n;i++){
            if(str[i]>=97 && str[i]<=122){
                low.push_back(str[i]);
            }
            else{
                up.push_back(str[i]);
            }
        }
       
        sort(low.begin(),low.end());
        sort(up.begin(),up.end()); 
        // for(int i=0;i<low.size();i++){
        //     cout<<up[i]<<" ";
        // }cout<<endl;
        // for(int i=0;i<)
        int k=0,j=0;
        string ans ="";
        for(int i=0;i<n;i++){
                if(str[i]>=97 && str[i]<=122)
                ans.push_back(low[k++]);
            else 
              ans.push_back(up[j++]);
        } 
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		string str;
		cin>>str;
		Solution obj;
		cout<<obj.caseSort (str, n)<<endl;
	}
}
// } Driver Code Ends