//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:
	int search(string pat, string txt) {
	    // code here
// 	    unordered_map<char,int>mp;
// 	    for(int i=0;i<pat.size();i++){
// 	        mp[pat[i]]++;
// 	    }
// 	    int n = txt.size();
// 	    int count = mp.size();
// 	    int w = pat.size();
// 	    int i=0;
// 	    int j=0;
// 	    int ans=0;
// 	    while(j<n){
// 	        if(mp.count(txt[j])){
// 	            mp[txt[j]]--;
// 	            if(mp[txt[j]]==0)count--;
// 	        }
// 	        if(j-i+1<w)j++;
// 	        else if(j-i+1==w){
// 	            if(count==0){
// 	                ans++;
// 	            }
// 	        if(mp.count(txt[i])){
// 	                if(mp[txt[i]]==1)count++;
// 	                mp[txt[i]]++;
// 	            }
// 	            i++;
// 	            j++;
// 	    }
// 	}
// 	    return ans;
   int patlen=pat.length();
        int txtlen=txt.length();
        int i=0;
        int j=0;
        
        unordered_map<char,int> freq;
        for(int i=0;i<patlen;i++)freq[pat[i]]++;
        int count=freq.size();
        int ans=0;
        
        while(j<txtlen)
        {
            if(freq.count(txt[j]))
            {
                freq[txt[j]]--;
                if(freq[txt[j]]==0)count--;
            }
            if(j-i+1<patlen)j++;
            else if(j-i+1==patlen)
            {
                if(count==0)ans++;
                if(freq.count(txt[i]))
                {
                    freq[txt[i]]++;
                    if(freq[txt[i]]==1)count++;
                }
                i++;
                j++;
            }
        }
        return ans;
	}

};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string pat, txt;
        cin >> txt >> pat;
        Solution ob;
        auto ans = ob.search(pat, txt);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends