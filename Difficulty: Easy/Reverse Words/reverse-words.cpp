//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    //Function to reverse words in a given string.
    string reverseWords(string S) 
    { 
        // code here 
        vector<string>st;
        string str ="";
        for(int i =0; i< S.length();i++){
              if(S[i] == '.'){
                //   st.push_back(".");
                st.push_back(str);
                str = "";
              }else{
                  str +=S[i]; 
              }
        }
        st.push_back(str);
        reverse(st.begin(), st.end());
        string ans;
        for(int i =0;i<st.size();i++){
            if(i == st.size() -1)cout<<st[i];
            else cout<< st[i]<<".";
        }
        // cout<<'.';
        return ans;
    } 
};

//{ Driver Code Starts.
int main() 
{
    int t;
    cin >> t;
    while (t--) 
    {
        string s;
        cin >> s;
        Solution obj;
        cout<<obj.reverseWords(s)<<endl;
    }
}
// } Driver Code Ends