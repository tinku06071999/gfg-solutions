//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
   bool isPalindrome(string& str){
        int i=0;
        int j = str.size()-1;
        while(i<j){
            if(str[i] != str[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    int addMinChar(string str){
        int n = str.size();
        string temp = "";
        temp+= str[0];
        int maxlen = 1;
        for(int i=1;i<n;i++){
            temp+= str[i];
            if(isPalindrome(temp)){
                maxlen = temp.size();
            }
        }
        return str.size()-maxlen;
        //code here
        
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
        cin >> str;
        
        Solution ob;
        cout << ob.addMinChar(str) << endl;
    }
    return 0; 
} 
// } Driver Code Ends