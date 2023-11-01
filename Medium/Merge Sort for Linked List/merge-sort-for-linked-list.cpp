//{ Driver Code Starts
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};


// } Driver Code Ends
/* Structure of the linked list node is as
struct Node 
{
    int data;
    struct Node* next;
    Node(int x) { data = x;  next = NULL; }
};
*/


class Solution{
  public:
    //Function to sort the given linked list using Merge Sort.
    Node* mergelist(Node* l1, Node* l2){
        Node* dummy = new Node(0);
        Node* curr = dummy;
        // if(!l1)return l2;
        // if(!l2)return l1;
        while(l1 && l2){
            if(l1->data <= l2->data){
                curr->next = l1;
                l1 = l1->next;
            }
            else{
                curr->next = l2;
                l2 = l2->next;
            }
            curr  = curr->next;
        }
        if(l1){
            curr->next = l1;
            l1 = l1->next;
        }
        if(l2){
            curr->next = l2;
            l2 = l2->next;
        }
        return dummy->next;
    }
    
    Node* mergeSort(Node* head) {
        // your code here
        if(head == nullptr||head->next == nullptr)return head;
        Node* slow = head;
        Node* fast = head;
        Node* temp = nullptr;
        while(fast && fast->next){
            temp = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        temp->next = nullptr;
        Node* l1 = mergeSort(head);
        Node* l2 = mergeSort(slow);
        return mergelist(l1,l2);
    }
};


//{ Driver Code Starts.

void printList(Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

void push(struct Node** head_ref, int new_data) {
    Node* new_node = new Node(new_data);

    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

int main() {
    long test;
    cin >> test;
    while (test--) {
        struct Node* a = NULL;
        long n, tmp;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> tmp;
            push(&a, tmp);
        }
        Solution obj;
        a = obj.mergeSort(a);
        printList(a);
    }
    return 0;
}
// } Driver Code Ends