//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int maxInstance(string s){
        map<char,int>mp;
        int n = s.length();
        for(int i=0;i<n;i++){
            if(s[i]=='b'|| s[i]=='a'|| s[i]=='l'||s[i]=='o'|| s[i]=='n')
            mp[s[i]]++;
        } 
            int a1 = mp['b'];
            int a2 = mp['a'];
            int a3 = mp['l']/2;
            int a4 = mp['o']/2;
            int a5 = mp['n'];
            return min(a1,min(a2,min(a3,min(a4,a5))));
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        Solution ob;
        cout<<ob.maxInstance(s)<<endl;
    }
    return 0;
}
// } Driver Code Ends