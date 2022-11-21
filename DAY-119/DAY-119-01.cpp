#include <bits/stdc++.h> 
using namespace std;
//Is it a Circular Linked List? 
//https://www.codingninjas.com/codestudio/problems/is-it-a-circular-linked-list_981265?leftPanelTab=0

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


bool circularLL(Node* head)
{
    if(head==NULL||head->next==NULL){
        return false;
        
    }
    Node *temp = head->next;
    while(temp!=NULL){
        if(temp==head){
            return true;
        }
        temp =temp->next;
        
    }
    return false;
}

