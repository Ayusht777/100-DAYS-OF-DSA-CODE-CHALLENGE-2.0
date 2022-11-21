#include <bits/stdc++.h> 
using namespace std;
// Sort linked list of 0s 1s 2s 
//https://www.codingninjas.com/codestudio/problems/sort-linked-list-of-0s-1s-2s_1071937?leftPanelTab=0


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
 
//approch 1
Node* sortList1(Node *head)
{
    int count0 = 0;
    int count1 =0;
    int count2=0;
    Node * temp = head;
    
    while(temp!=NULL){
        if(temp->data==0){
            count0++;
            temp= temp->next;
        }
         else if(temp->data==1){
            count1++;
            temp= temp->next;
         }
        else if (temp->data==2){
             
            count2++;
            temp= temp->next;
             
            
        }
    }
    temp =head;
    while(temp!=NULL){
        if(count0!=0){
            temp->data = 0;
            count0--;
        }
        else if(count1!=0){
             temp->data = 1;
            count1--;
        }
        else if(count2!=0){
              temp->data = 2;
            count2--;
        }
         temp= temp->next;
    }
    
    return head;

}

//apporach 2
void insertatail(Node * &tail,Node *curr){
    tail->next =curr;
    tail =curr;
    
}
Node* sortList(Node *head)
{
    //dummuy list
 Node *zerohead = new Node(-1);
 Node *zerotail = zerohead;
  Node *onehead = new Node(-1);
 Node *onetail = onehead;
    Node *twohead = new Node(-1);
 Node *twotail = twohead;
    
    Node *curr =head;
    
    // create a spearted list of 0s 1s 2s
    while(curr!=NULL){
        int value =curr->data;
        if(value == 0){
            insertatail(zerotail,curr);
            
        }
        else if(value == 1){
            insertatail(onetail,curr);
            
         }
        else if(value == 2){
            insertatail(twotail,curr);
            
         }
        curr = curr->next;
    }
    
    //merge the dummy list 
    
    
    //1 ki list not empty
    if(onehead->next!=NULL){
        zerotail->next =onehead->next;
    }
    else{
        zerotail->next =twohead->next;
    }
     onetail->next = twohead->next;
    twotail->next =NULL;
    
    //remevome head
    
   head =zerohead->next ;
    
    //delete dummy
    delete zerohead;
    delete onehead;
    delete twohead;
    
    return head;
    
}
