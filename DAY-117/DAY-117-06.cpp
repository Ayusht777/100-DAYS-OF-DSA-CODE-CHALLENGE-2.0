#include <bits/stdc++.h> 
using namespace std;
// Reverse a Doubly Linked List using Iteration
//https://practice.geeksforgeeks.org/problems/reverse-a-doubly-linked-list/1

class Node{
        public:
	        int data;
	        Node *next;
            Node * per;
	        Node(int data)
	        {
		        this->data = data;
		        this->next = NULL;
                this->per =NULL;
	        }
};

Node* reverseLinkedList(Node *head)
{    //ye empty list    1 list
    if(head ==NULL || head->next ==NULL){
        return head;
    }
    Node * temp = head;
    Node *store =NULL;
     
    
    while(temp!=NULL){
        store = temp->per;
        temp->per = temp->next;
        temp->next =store;
        //swapping logi cabove

        temp =temp->per; 


        
        
    }
    return store->per;
}

