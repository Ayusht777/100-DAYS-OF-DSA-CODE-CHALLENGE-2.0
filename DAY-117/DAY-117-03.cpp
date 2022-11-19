#include <bits/stdc++.h> 
using namespace std;
// Reverse Linked List  using Recurively Solution -2
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



Node* reverse(Node *&head){
    //base case 
    if(head==NULL || head->next ==NULL ){
         
        return head;
    }
    Node * smallhead = reverse(head->next);

    head->next->next = head;
    head->next = NULL;

    return smallhead;

   
    
    
}
Node* reverseLinkedList(Node *head)
{   
    return(reverse(head));
}




