//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node* next;
	
	Node(int x){
	    data = x;
	    next = NULL;
	}
	
};


// } Driver Code Ends
/*
// structure of the node is as follows

struct Node
{
	int data;
	struct Node* next;
	
	Node(int x){
	    data = x;
	    next = NULL;
	}
	
};

*/
class Solution
{
    public:
    struct Node* makeUnion(struct Node* head1, struct Node* head2)
    {
        // code here
        vector<int>v1;
        Node* temp1 = head1;
        Node* temp2 = head2;
        
        while(temp1 || temp2){
            if(temp1){
                v1.push_back(temp1->data);
                temp1 = temp1->next;
            }
            if(temp2){
                v1.push_back(temp2->data); 
                temp2 = temp2->next;
            }
           
        }
       
        sort(v1.begin(),v1.end());
        head1 = new Node(v1[0]);
        temp1 = head1;
       Node* newnode = nullptr;
       for(int i=1;i<v1.size();i++){
           if(v1[i]==v1[i-1])continue;
           else{
           newnode = new Node(v1[i]);
           temp1->next = newnode;
           temp1 = temp1->next;
           }
       }
        return head1;
    }
};


//{ Driver Code Starts.

struct Node* buildList(int size)
{
    int val;
    cin>> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}


int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        
        cin>>n;
        Node* first = buildList(n);
        
        cin>>m;
        Node* second = buildList(m);
        Solution obj;
        Node* head = obj.makeUnion(first,second);
        printList(head);
    }
    return 0;
}

// } Driver Code Ends