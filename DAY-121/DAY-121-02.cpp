#include <bits/stdc++.h> 
using namespace std;
// Merge Sort Linked List 
//https://www.codingninjas.com/codestudio/problems/merge-sort-linked-list_920473?leftPanelTab=0
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

Node *findmid(Node * head){
    Node * slow =head;
    Node *fast =head->next;
    
    while(fast!=NULL && fast->next !=NULL){
        slow =slow->next;
        fast = fast->next->next;
        
    }
    return slow;
}

Node * merge(Node *left,Node * right ){
    if(left==NULL){
        return right;
        
    }
    if(right ==NULL){
        return left;
    }
    //dummy node
    Node * ans = new Node (-1);
    Node * temp =ans;
    
    while(left!=NULL&&right !=NULL){
        if(left->data < right ->data ){
            temp->next = left;
            temp =left;
            left =left->next;
            
        }
        else{
            temp->next = right;
            temp =right;
            right =right->next;
            
        }
    }
    
    while(left!=NULL){
           temp->next = left;
            temp =left;
            left =left->next;
    }
    
    while(right!=NULL){
         temp->next = right;
            temp =right;
            right =right->next;
    }
    //dummy node ko hayta
    ans = ans->next;
    
    return ans;
    
    
}

Node * merge(){
    
}
Node *sortLL(Node *head){
    if(head==NULL||head->next==NULL){
        return head;
    }
    
    Node *mid  =findmid(head);
    
    
    Node *left =head;
   Node *right =mid->next;
    mid->next =NULL;
    
    
    
    left =sortLL(left);
    right =sortLL(right);
    
    
    Node * result =merge(left,right);
    return result;
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
}