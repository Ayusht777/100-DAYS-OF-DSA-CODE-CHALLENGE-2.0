#include <bits/stdc++.h> 
using namespace std;
//Remove Duplicates From an Unsorted Linked List 
//Remove duplicates from an unsorted linked list
//Remove duplicates from an unsorted linked list
//https://www.codingninjas.com/codestudio/problems/remove-duplicates-from-unsorted-linked-list_1069331?leftPanelTab=0


    class Node 
    {
        public:
        int data;
        Node* next;

        Node(int data) 
        {
            this->data = data;
            this->next = NULL;
        }
    };
 //TLE MARA RAHA HAI   
Node *removeDuplicates1(Node *head)
{
    if(head ==NULL ){
        return NULL;
    }
  
    
    Node * curr =head;
    
    while(curr!=NULL && curr->next !=NULL){
         Node * temp =curr;
        while(temp->next !=NULL){
            if(curr->data == temp->next->data){
                Node * node_node = temp->next;
                
                temp->next = temp->next->next;
                delete(node_node);
                
            }
            else{
                temp = temp->next;
            }
           
        
           
        
    }
         curr =curr->next;
}
   return head; 
}
//using hasmaps
#include<unordered_map>
Node *removeDuplicates(Node *head)
{
    if(head ==NULL ){
        return NULL;
    }
    
    unordered_map <int,bool> visted;
    Node * curr= head;
    Node * per =NULL;
    while(curr!=NULL){
        if(visted[curr->data]!=true){
            visted[curr->data]=true;
            per= curr;
            curr =curr->next;
        }
        else{
            per->next = curr->next;
            Node * t= curr;
            delete(t);
            curr = curr->next;
        }
    }
  
    
    return head;
    
    
    
}