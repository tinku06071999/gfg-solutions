//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

void printList(Node *node)
{
    while (node != NULL)
    {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}

struct Node *inputList()
{
    int n; // length of link list
    scanf("%d ", &n);

    int data;
    cin >> data;
    struct Node *head = new Node(data);
    struct Node *tail = head;
    for (int i = 0; i < n - 1; ++i)
    {
        cin >> data;
        tail->next = new Node(data);
        tail = tail->next;
    }
    return head;
}


// } Driver Code Ends
//User function Template for C++

/*
Definition for singly Link List Node
struct Node
{
    int data;
    struct Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};
*/


class Solution
{
public:
   
    vector<int> rev(vector<int>&v,int str,int end){
        int i=str;
        int j=end-1;
        while(i<=j){
            int temp = v[i];
            v[i]=v[j];
            v[j] = temp;
            i++,j--;
        }
        return v;
    }
    Node *reverse(Node *head, int k)
    {
        // code here
        vector<int>v;
        
       while(head!=nullptr){
           v.push_back(head->data);
           head = head->next;
       }
       rev(v,0,k);
       int n = v.size();
       rev(v,k,n);
    //   for(int i=0;i<n;i++){
    //       cout<<v[i]<<" ";
    //   }cout<<endl;
    
       head = new Node(v[0]);
       Node* curr = head;
    for(int i=1;i<n;i++){
        Node* temp = new Node(v[i]);
        curr->next = temp;
        curr = temp;
    }
    return head;
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        struct Node *head = inputList();
        int k;
        cin >> k;

        Solution obj;
        Node *res = obj.reverse(head, k);

        printList(res);
    }
}
// } Driver Code Ends