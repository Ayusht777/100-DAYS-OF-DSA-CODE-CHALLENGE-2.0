#include <bits/stdc++.h> 
using namespace std;
//Middle Of Linked List Method -1
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


int getlen(Node *head){
    int len =0;
    while(head != NULL){
        len++;
        head = head->next;
        
    }
    return len;
}
Node *findMiddle(Node *head) {
   int l =  getlen(head);
   int mid = (l/2);
    //both for odd and even case
    
    Node *temp =head;
    int cnt =0;
    while(cnt < mid){
        temp = temp->next;
        cnt++;
    }
   
    
    return temp;
    
    
 }


