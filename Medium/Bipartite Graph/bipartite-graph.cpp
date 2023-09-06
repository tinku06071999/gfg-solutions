//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    bool solve(int sr, vector<int>adj[],vector<int> &vis){
       queue<int>q;
	    q.push(sr); 
	    vis[sr] = 0;
	    while(!q.empty()){
	    int node = q.front();
	    q.pop();
	    for(auto it : adj[node ]){
	        if(vis[it] == -1 ){
	            vis[it] = !vis[node];
                q.push(it);
	        }
	        else if(vis[it] ==  vis[node] ){
	           return false;
	        }
	     }
	    }
	    return true;
    }

bool dfs(int sr, int col,vector<int>adj[],vector<int> &vis){
    vis[sr] = col;
    for(auto it : adj[sr]){
        if(vis[it] == -1){
            if(!dfs(it,!col,adj,vis))return false;
        }
        else if(vis[it] == vis[sr])return false;
    }
    return true;
}
	bool isBipartite(int V, vector<int>adj[]){
	    // Code here
	    vector<int>vis(V,-1);
	   for(int i=0;i<V;i++){
	       if(vis[i] == -1)
	         if(dfs(i,0,adj,vis) == 0) return false;
	  }
	     return true;
	}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}
// } Driver Code Ends