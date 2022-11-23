#include <bits/stdc++.h> 
using namespace std;
//Clone a linked list with next and random pointer
// https://practice.geeksforgeeks.org/problems/clone-a-linked-list-with-next-and-random-pointer/1
 //method 1   
struct Node {
    int data;
    Node *next;
    Node *arb;

    Node(int x) {
        data = x;
        next = NULL;
        arb = NULL;
    }
};


class Solution
{   private:
    void insertatail(Node *&head,Node * &tail,int d){
        Node * newnode =new Node(d);
        if(head ==NULL){
            head =newnode;
            tail =newnode;
            return;
            }
        else{
            tail->next =newnode;
            tail= newnode;
        }    
    }
    public:
    Node *copyList(Node *head)
    {
        Node *clonehead = NULL;
        Node *clonetail =NULL;
        
        Node * temp = head;
        
        while(temp!=NULL){ 
            insertatail(clonehead,clonetail,temp->data);
            temp = temp->next;
    
      }  
      
      unordered_map<Node * ,Node *> oldTonewnode;
      
      Node * originalnode =head;
      Node * clonenode = clonehead;
      
      while(originalnode != NULL&& clonenode!=NULL){
          
          oldTonewnode[originalnode]=clonenode;
         originalnode = originalnode->next;
         clonenode =clonenode->next;
          
      }
       
       originalnode =head;
       clonenode =clonehead;
       
       while(originalnode!=NULL){
           clonenode->arb =oldTonewnode[originalnode->arb];
           originalnode = originalnode->next;
           clonenode =clonenode->next;
           
       }
       
       return clonehead;
      
     
        
        
        
        
    }

};




