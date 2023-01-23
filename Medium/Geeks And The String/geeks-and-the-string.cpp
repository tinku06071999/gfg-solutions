//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    string removePair(string s) {
        // code here
        stack<int>st;
        string ans = "";
     
        for(int i=0;i<=s.size()-1;i++){
            //   st.push(s[i]);
            // while(!st.empty()){
                if(!st.empty() && st.top()==s[i]){
                    st.pop();
                }
                else{
                    st.push(s[i]);
                }
            // }
        }
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        int len = ans.length();
        if(len)return ans;
        return "-1";
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string s; 
        cin>>s;
        
        Solution obj;
        string res = obj.removePair(s);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends