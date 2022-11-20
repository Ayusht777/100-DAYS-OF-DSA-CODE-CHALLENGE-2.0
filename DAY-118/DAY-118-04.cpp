#include <bits/stdc++.h> 


using namespace std;
//Detect Loop in linkedlist Using Floyd’s Cycle Finding Algorithm
//

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


Node * floydetectloop(Node *head){
    if(head ==NULL){
    return NULL;

    }

    
    Node * slow =head;
    Node * fast = head->next;


    while (slow!=NULL&&fast!=NULL)
    {
        fast = fast->next->next;
        slow = slow->next;

        if(slow == fast){
            cout<<"Slow == "<<slow->data<<endl;
            return slow;
            // yani loop hai
        }

    }
    
    return NULL;


}





int main(){
    Node *n = new Node(10);
    Node *head = n;
    Node *tail =n;
    InsertAtTail(tail,15);
    InsertAtTail(tail,26);
    tail->next = head->next;
    // print(head);
   cout<<"head  "<<head->data <<endl;
   cout<<"tail "<<tail->data<<endl;

    if(floydetectloop(head)!= NULL){
        cout<<"it is a loop"<<endl;
    }
    else{
        cout<<"not loop"<<endl;
    }



}
