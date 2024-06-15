//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    //Function to find the first non-repeating character in a string.
    char nonrepeatingCharacter(string S)
    {
       //Your code here
       vector<int>arr(26, 0);
       
       for(int i=0;i<S.size();i++){
           int idx = S[i] - 97;
        //   cout<<S[i]<<" "<<idx;
           arr[idx]++;
       }
       for(int i=0;i<S.size();i++){
           int idx = S[i] - 97;
           if(arr[idx] == 1){
            //   cout<< 'a' + i;
               return ('a' + idx);
           }
       }
       return '$';
    }

};

//{ Driver Code Starts.

int main() {
	
	int T;
	cin >> T;
	
	while(T--)
	{
	
	    string S;
	    cin >> S;
	    Solution obj;
        char ans = obj.nonrepeatingCharacter(S);
        
        if(ans != '$')
	    cout << ans;
        else cout << "-1";
            
        cout << endl;
	    
	}
	
	return 0;
}

// } Driver Code Ends