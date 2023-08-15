//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:
	int search(string pat, string txt) {
	    // code here
	    int n=txt.size();
	    int w = pat.size();
	    int ans=0;
	    unordered_map<char,int>mp;
	    for(int i=0;i<w;i++){
	        mp[pat[i]]++;
	    }
	    int i=0,j=0;
	    int cnt = mp.size();
	    while(j<n){
	        if(mp.count(txt[j])){
	            mp[txt[j]]--;
	            if(mp[txt[j]]==0)cnt--;
	        }
	        if(j-i+1<w)j++;
	        else if(j-i+1==w){
	            if(cnt==0)ans++;
	            if(mp.count(txt[i])){
	                mp[txt[i]]++;
	                if(mp[txt[i]]==1)cnt++;
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