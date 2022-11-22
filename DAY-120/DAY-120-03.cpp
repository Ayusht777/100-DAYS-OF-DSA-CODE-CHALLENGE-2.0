#include <bits/stdc++.h> 

#include<vector>
using namespace std;
//Check if Linked List is Palindrome Method - 2 
//https://practice.geeksforgeeks.org/problems/check-if-linked-list-is-pallindrome/1
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};


class Solution{
    private:
    Node * getmid(Node * head){
        Node * slow  =head;
        Node * fast = head->next;
        while(fast!=NULL&&fast->next!=NULL){
            fast = fast->next->next;
            slow = slow->next;
            
        }
        return slow;
    }
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
    
  public:
    //Function to check whether the list is palindrome.
    bool isPalindrome(Node *head)
    {
        if( head->next ==NULL ){
            return true;
        }
        Node * mid = getmid(head);
        
        
        //tarves from middle
        
        Node * temp =mid->next;
        
       mid->next = reverse(temp);
        
        //compare bothe lsit
        Node * head1 = head;
         Node *  head2 =mid->next;
        while(head2!=NULL){
            if(head1->data != head2->data){
                return false;
            }
            head1= head1->next;
            head2= head2->next;
            
        }
        
        temp =mid->next;
        mid->next = reverse(temp);
        
        return true;
      
    }
};