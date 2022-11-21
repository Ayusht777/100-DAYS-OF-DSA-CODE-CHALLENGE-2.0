#include <bits/stdc++.h> 
using namespace std;
//Remove Duplicates From Sorted List 
//83. Remove Duplicates from Sorted List
//Remove duplicate element from sorted Linked List

//https://www.codingninjas.com/codestudio/problems/unique-sorted-list_2420283?leftPanelTab=0



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
    


Node * uniqueSortedList(Node * head) {
    // Write your code here.
    if(head ==NULL ){
        return NULL;
    }
    Node * temp =head;
    while(temp!=NULL && temp->next !=NULL){
        if(temp->data == temp->next->data){
            Node * next_next = temp->next->next;
         Node * nodetodelete =temp->next;
            delete(nodetodelete);
              temp->next = next_next;
        }
        else{ 
            
            temp =temp->next;
         }
      
           
        
    }
    return head;
}

