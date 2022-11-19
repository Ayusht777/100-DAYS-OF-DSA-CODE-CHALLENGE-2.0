#include <bits/stdc++.h> 
using namespace std;
// Reverse Linked List  using Iteration
// https://www.codingninjas.com/codestudio/problems/reverse-linked-list_920513?leftPanelTab=0

class Node{
        public:
	        int data;
	        Node *next;
	        Node(int data)
	        {
		        this->data = data;
		        this->next = NULL;
	        }
};


Node* reverseLinkedList(Node *head)
{    //ye empty list    1 list
    if(head ==NULL || head->next ==NULL){
        return head;
    }
    Node * curr = head;
    Node *per =NULL;
     Node *forward =NULL;
    
    while(curr!=NULL){
        forward = curr->next;
        curr->next =per;
        per=curr;
        curr = forward;
        
        
    }
    return per;//joki head hogya 
}


