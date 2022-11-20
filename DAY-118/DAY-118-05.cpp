#include <bits/stdc++.h> 
//Detect and Remove Loop
//https://www.codingninjas.com/codestudio/problems/interview-shuriken-42-detect-and-remove-loop_241049?leftPanelTab=0

using namespace std;


class Node{

    public:

    int data;
    Node *next ; //here we are creating pointer of node data tyep which will store the address of next node 
 
  
 //let create a constructor to store data
///constructor
    Node(int data){

        this->data = data;
        this->next = NULL; //to null pointer

    }

    //destrcutor

    ~Node(){
        int value  = this->data;
        //memory free

        if(this->next!=NULL){
            delete next;
            this->next = NULL;
        }

        cout<<"Memory free "<<value<<endl;
    }


};

void InsertAtHead(Node * &head,int d){
    Node *temp = new Node(d);
    temp->next = head;
    //temp node ka pointer ko prnai node ka head ya address of data pa point kar rhah ha
    head =temp; 
    //phir head to temp ki node sa
}

void InsertAtTail(Node * &tail,int d){
    Node * temp = new Node(d);

   tail->next = temp;
//    tail = tail->next;
//easy
    tail =temp;



}

void InsertAtPosition(Node * &tail,Node * &head,int position,int d){
  //inseration at start
    if(position ==1){
        InsertAtHead(head,d);
        return;
    }
   
    Node * temp = head;
    int cnt =1;
    
    while (cnt<position-1)
    {
        temp = temp->next;
        cnt++;
    }

    // inseration at tail or end
    if(temp->next ==NULL){
       InsertAtTail(tail,d);
       return; 
    }
    Node *nodetoinsert = new Node(d);
    nodetoinsert->next = temp->next;
    temp->next = nodetoinsert;
    

}

void deleteNode(int pos,Node * &head){
    //delete at start
    if(pos==1){
        Node *temp =head;
        head=head->next;
        //TEMP FREE
        temp ->next =NULL;
        delete temp;
    }
    // ladt ya midle pos
    else{
        Node *curr =head;
        Node *per =NULL;

        int cnt =1;
        while (cnt<pos)
        {
             per = curr;
             curr = curr->next;
             cnt++;

        }

        per->next = curr->next;
        curr->next =NULL;
        delete curr;
        


    }


}

void print(Node * &head){
    Node *temp =head;
    while (temp!=NULL)
    {
        cout<<temp->data<<" "<<endl;
        temp = temp->next;

       
    }
    
    cout<<endl;
}

Node* floydDetectLoop(Node* head) {

    if(head == NULL)
        return NULL;

    Node* slow = head;
    Node* fast = head;

    while(slow != NULL && fast !=NULL) {
        
        fast = fast -> next;
        if(fast != NULL) {
            fast = fast -> next;
        }

        slow = slow -> next;

        if(slow == fast) {
            return slow;
        }
    }

    return NULL;

}

Node* getStartingNode(Node* head) {

    if(head == NULL) 
        return NULL;

    Node* intersection = floydDetectLoop(head);
    
    if(intersection == NULL)
        return NULL;
    
    Node* slow = head;

    while(slow != intersection) {
        slow = slow -> next;
        intersection = intersection -> next;
    }  

    return slow;

}

Node *removeLoop(Node *head)
{
    if( head == NULL)
        return NULL;

    Node* startOfLoop = getStartingNode(head);
    
    if(startOfLoop == NULL)
        return head;
    
    Node* temp = startOfLoop;

    while(temp -> next != startOfLoop) {
        temp = temp -> next;
    } 

    temp -> next = NULL;
    return head;
}





int main(){
    Node *n = new Node(10);
    Node *head = n;
    Node *tail =n;
    InsertAtTail(tail,15);
    InsertAtTail(tail,26);
    InsertAtTail(tail,27);
    tail->next = head->next;
    // print(head);
   cout<<"head  "<<head->data <<endl;
   cout<<"tail "<<tail->data<<endl;

   Node * nx =getStartingNode(head);
   cout<<"loop starts "<<nx->data<<endl;
 
//    removeloop(head);


}
