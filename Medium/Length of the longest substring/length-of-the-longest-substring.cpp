//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int longestUniqueSubsttr(string S){
        //code
        vector<int>mp(26,0);
        int i=0,j=0;
        int n = S.length();
        int maxi =1;
        while(j<n){
            while(mp[S[j]-'a']>0){
                mp[S[i]-'a']--;
                i++;
            }
                maxi = max(maxi,j-i+1);
                mp[S[j]-'a']++;
                j++;
        }
        return maxi;
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string str;
		cin>>str;
		Solution ob;
		cout<<ob.longestUniqueSubsttr(str)<<endl;
	}
	return 0;
}
// } Driver Code Ends