#include <bits/stdc++.h> 
using namespace std;
//SinglyLinedklist


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


int main(){
    Node *node1 = new Node(10);
    // cout<<node1->data<<endl;// because it is apointer so we have to use ->
    // cout<<node1->next<<endl;
   Node *head = node1;
   Node *tail = node1;
    // print(node1);


    InsertAtTail(tail,15);
    print(head);
    InsertAtTail(tail,9);
    print(head);

      cout<<"-----------------------------------------------"<<endl;
  
    //   print(tail);
    //   InsertAtTail(tail,12);
    //   print(tail); 

    //  InsertAtPosition(head,4,29);
    //  print(head);
     InsertAtPosition(tail,head,4,8);
     print(head);
    cout<<"head "<<head->data<<endl;
    cout<<"tail "<<tail->data<<endl;
    deleteNode(3,head);
    print(head);


}