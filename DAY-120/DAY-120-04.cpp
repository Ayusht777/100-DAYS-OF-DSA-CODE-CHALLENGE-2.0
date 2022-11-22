#include <bits/stdc++.h> 

#include<vector>
using namespace std;
//Add two numbers represented by linked lists 
//https://practice.geeksforgeeks.org/problems/add-two-numbers-represented-by-linked-lists/1
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};


struct Node* buildList(int size)
{
    int val;
    cin>> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}


class Solution
{  private:
    Node * reverse(Node * head){
        Node * curr = head;
        Node * per =NULL;
        Node * next = NULL;
        while(curr!=NULL){
            next = curr->next;
            curr->next= per;
            per =curr;
            curr =next;
        }
        return per;
    }
    void insertatatil(struct Node* &head, struct Node*&tail,int val){
        Node * temp =new Node(val);
        if(head==NULL){
            head =temp;
            tail =temp;
            return ;
        }
        else{
            tail->next =temp;
            tail =temp;
        }
        
        
    }
    struct Node* add(struct Node* first, struct Node* second){
        int carry=0;
        Node * anshead =NULL;
        Node *anstail =NULL;
       while(first!=NULL && second !=NULL){
           int sum = carry +first->data +second->data;
           int digit = sum %10;
           
           insertatatil(anshead,anstail,digit);
           carry = sum/10;
           first = first->next;
           second =second->next;
           
       }
       
       while(first!=NULL){
           int sum = carry +first->data;
           int digit = sum %10;
          
           insertatatil(anshead,anstail,digit);
           carry = sum/10;
           first = first->next;
          
       }
       
        while(second!=NULL){
           int sum = carry +second->data;
           int digit = sum %10;
          
           insertatatil(anshead,anstail,digit);
           carry = sum/10;
       
           second =second->next;
           
       }
       
       while(carry!=0){
        int sum = carry;
           int digit = sum %10;
          
           insertatatil(anshead,anstail,digit);
           carry = sum/10;
  
       }
        return anshead;
    }
    
    public:
    //Function to add two numbers represented by linked list.
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
       first = reverse(first);
       second = reverse(second);
       
       Node * ans =add(first,second);
       
       return (reverse(ans));
    }
};
