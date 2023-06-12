//{ Driver Code Starts
// driver

#include <bits/stdc++.h>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

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


// } Driver Code Ends
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    //Function to add two numbers represented by linked list.
    void reverse(Node* &head){
        Node* prev = nullptr;
        Node* curr = head;
        Node* next = nullptr;
        
        while(curr!= nullptr){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        head = prev;
         
    }
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
        // code here
        reverse(first);
        reverse(second);
        int carry =0;
        int sum =0;
        Node* start = new Node(0);
        Node* curr= start;
        Node* temp = nullptr;
        while(first || second || carry){
            sum=0;
            if(first){
                sum+= first->data;
                first = first->next;
            }
            if(second){
                sum+=second->data;
                second = second->next;
            }
            sum+=carry;
            carry = sum/10;
            sum = sum%10;
            temp = new Node(sum);
            curr->next = temp;
            curr = curr->next;
        }
         reverse(start->next);
        return start->next;
    }
};


//{ Driver Code Starts.

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
        Solution ob;
        Node* res = ob.addTwoLists(first,second);
        printList(res);
    }
    return 0;
}

// } Driver Code Ends