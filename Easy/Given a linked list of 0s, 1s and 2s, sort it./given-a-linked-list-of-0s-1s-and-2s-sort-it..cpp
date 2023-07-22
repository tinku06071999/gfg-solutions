//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;
/* Link list Node */
struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node *start = NULL;


// } Driver Code Ends
/*
 
  Node is defined as
  struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/
class Solution
{
    public:
    //Function to sort a linked list of 0s, 1s and 2s.
    Node* segregate(Node *head) {
       Node* dummy1 = new Node(0);
       Node* hed = dummy1;
       Node* dummy2 = new Node(0);
       Node* mid = dummy2;
       Node* dummy3 = new Node(0);
       Node* end = dummy3;
       while(head){
           if(head->data == 0){
               Node* temp1 = new Node(head->data);
               hed->next = temp1;
               hed = temp1;
           }
           else if(head->data == 1){
               Node* temp2 = new Node(head->data);
               mid->next = temp2;
               mid = temp2;
           }
           else{
               Node* temp3 = new Node(head->data);
               end->next = temp3;
               end = temp3;
           }
           head = head->next;
       }
       
       if(!dummy1->next && !dummy2->next)return dummy3->next;
       if(!dummy1->next && dummy2->next){
           mid->next = dummy3->next;
           return dummy2->next;
       }
       if(dummy1->next && !dummy2->next){
           hed->next = dummy3->next;
           return dummy1->next;
       }
       hed->next = dummy2->next;
       mid->next = dummy3->next;
       return dummy1->next;
       
    }
};


//{ Driver Code Starts.

// Function to sort a linked list of 0s, 1s and 2s
void printList(struct Node *Node) {
    while (Node != NULL) {
        printf("%d ", Node->data);
        Node = Node->next;
    }
    printf("\n");
}

/* Drier program to test above function*/
void insert(int n1) {
    int n, value, i;
    // scanf("%d",&n);
    n = n1;
    struct Node *temp;
    for (i = 0; i < n; i++) {
        scanf("%d", &value);

        if (i == 0) {
            start = new Node(value);
            temp = start;
            continue;
        } else {
            temp->next = new Node(value);
            temp = temp->next;
            temp->next = NULL;
        }
    }
}

int main() {

    int n;

    int t;
    scanf("%d", &t);

    while (t--) {
        scanf("%d", &n);

        insert(n);
        Solution ob;
        struct Node *newHead = ob.segregate(start);
        printList(newHead);
    }

    return 0;
}
// } Driver Code Ends