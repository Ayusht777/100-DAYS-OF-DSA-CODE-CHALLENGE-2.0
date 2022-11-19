#include <bits/stdc++.h> 
using namespace std;
//Middle Of Linked List  Method -2
//https://www.codingninjas.com/codestudio/problems/middle-of-linked-list_973250?leftPanelTab=0
//https://www.codingninjas.com/codestudio/problems/middle-of-linked-list_973250?leftPanelTab=0

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


Node * getmid(Node *head){
   
    if(head==NULL||head->next ==NULL){
        return head;
    }
    //2 nodes
    if(head->next->next==NULL){
        return head->next;
    }
    
    Node *fast =head->next;
    Node *slow =head;
    while(fast!=NULL){
        fast = fast->next;
        if(fast !=NULL){
            fast = fast->next;
        }
        slow =slow->next;
        
       
    }
     return slow;
   
}
Node *findMiddle(Node *head) {
   return getmid(head);
    
 }


