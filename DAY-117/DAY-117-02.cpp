#include <bits/stdc++.h> 
using namespace std;
// Reverse Linked List  using Recurively Solution -1
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



void reverse(Node *&head,Node * curr,Node * per){
    //base case 
    if(curr ==NULL){
        head = per;
        return;
    }
    //Node *& forward = curr->next;
    // perv->next === curr ha
    reverse(head,curr->next,curr);
    
    curr->next = per;
    
    
    
}
Node* reverseLinkedList(Node *head)
{   
    Node * curr = head;
    Node *per =NULL;
    reverse(head,curr,per);
    return head;
}




