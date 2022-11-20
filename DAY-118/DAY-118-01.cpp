#include <bits/stdc++.h> 
using namespace std;
// Reverse List In K Groups 
//https://www.codingninjas.com/codestudio/problems/reverse-list-in-k-groups_983644?leftPanelTab=0

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


Node* kReverse(Node* head, int k) {
    //base case
    if(head==NULL){
        return NULL;
    }
    Node *curr = head;
    Node *per = NULL;
    Node * forward = NULL;
    int count=0;
    
    while(curr!=NULL && count<k){
        forward = curr->next;
        curr->next = per;
        per = curr;
        curr = forward;
        count++;
        
    }
    //recursive call
    if(forward !=NULL){
        head->next = kReverse(forward,k);
    }
    
    return per;
    
    
}

