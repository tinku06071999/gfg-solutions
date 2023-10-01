//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    
    return temp;
}
Node* buildTree(string str)
{   
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
            return NULL;
    
    // Creating vector of strings from input 
    // string after spliting by space
    vector<string> ip;
    
    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);
        
    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));
        
    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);
        
    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {
            
        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();
            
        // Get the current node's value from the string
        string currVal = ip[i];
            
        // If the left child is not null
        if(currVal != "N") {
                
            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->left);
        }
            
        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];
            
        // If the right child is not null
        if(currVal != "N") {
                
            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }
    
    return root;
}
long long treePathsSum(Node *root);

int main()
{
    int t;
	scanf("%d ",&t);
    while(t--)
    {
        string s;
		getline(cin,s);
		Node* root = buildTree(s);
		
        cout<<treePathsSum(root);
   		cout<<endl;
  }
  return 0;
}

// } Driver Code Ends


/* Tree node structure  used in the program
 struct Node
 {
     int data;
     Node* left, *right;
}; */

/*You are required to complete below method */
void solve(Node* root,vector<vector<int>>&ans, vector<int>&temp){
    if(!root)return;
    temp.push_back(root->data);
    if(!root->left && !root->right){
        ans.push_back(temp);
    }
    solve(root->left,ans,temp);
    solve(root->right,ans,temp);
    temp.pop_back();
}
long long treePathsSum(Node *root)
{
    //Your code here
    vector<vector<int>>ans;
    vector<int>temp;
    solve(root,ans,temp);
    int n = ans.size();
    
    long long fans=0;
    // for(int i=0;i<n;i++){
    //     // long long res=0; 
    //     for(int j=0;j<m;j++){
    //         cout<<ans[i][j]<<" ";
    //     }
    //     // cout<<endl;
    // }
    for(int i=0;i<n;i++){
        long long res=0; 
        int m = ans[i].size();
        for(int j=0;j<m;j++){
            res = res*10+ans[i][j];
        }
        fans+=res;
    }
    return fans;
}
