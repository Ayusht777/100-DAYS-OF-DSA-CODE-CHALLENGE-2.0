#include <bits/stdc++.h> 
using namespace std;
//DoublyLinedklist

class Node{

    public:

    int data;
    Node *perv ;
    Node *next; 
 
  
 //let create a constructor to store data
///constructor
    Node(int data){

        this->data = data;
        this->perv =NULL;
        this->next = NULL; //to null pointer

    }

    //destrcutor
    ~Node(){
        int val =this->data;
        if(next!=NULL){
            delete next;
            next =NULL;
        }
        cout<<"Memory free"<<endl;
    }

    


};

void insertathead(Node *&tail,Node * &head,int d){
  //agar head null ha 
  if(head==NULL){
    Node *temp = new Node(d);
    head = temp;
    tail=temp;
  }
  else{
      Node *temp = new Node(d);
    temp->next = head;
    head->perv =temp ; ///temp->next;
    head = temp;
  }


}

void insertattail(Node *&tail,Node * &head,int d){
   if (tail==NULL)
   {
     Node *temp = new Node(d);
      tail =temp;
      head = temp;
   }

   else{
     Node *temp = new Node(d);
    tail->next = temp; 
    temp->perv = tail;
    tail =temp;
   }
   


}


void InsertAtPosition(Node * &tail,Node * &head,int position,int d){
  //inseration at start
    if(position ==1){
        insertathead(tail,head,d);
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
       insertattail(tail,head,d);
       return; 
    }
    Node *nodetoinsert = new Node(d);
    nodetoinsert->next = temp->next;
    temp->next->perv = nodetoinsert;
    temp->next =nodetoinsert;
    nodetoinsert->perv =temp;
    

}
void deleteNode(int pos,Node * &head){
    //delete at start
    if(pos==1){
        Node *temp =head;
       
        temp ->next->perv =NULL;
        head =temp->next;
        temp->next = NULL;
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
        
        curr->perv =NULL;
        per->next =curr->next;
        curr->next =NULL;
        delete curr;
    }


}

void print(Node *head){
    Node *temp = head;
    while (temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    } 
    cout<<endl;
    
}

int getlength(Node *head){
       Node *temp = head;
       int len =0;
    while (temp!=NULL)
    {   len++;
        temp = temp->next;
    } 
    return len;
    

}


int main(){
    // Node *n1 = new Node (15);
    Node* head = NULL; //n1 ka head ko point kar rahi hai
    Node * tail=NULL;
    print(head);
    cout<<getlength(head)<<endl;
    insertathead(tail,head,10);
    print(head);
    
    insertathead(tail,head,9);
    print(head);
    insertathead(tail,head,8);
    print(head);
    insertattail(tail,head,18);
    print(head);
    cout<<"head "<<head->data<<endl;
    cout<<"Tail "<<tail->data<<endl;
    InsertAtPosition(tail,head,2,480);

    print(head);
    deleteNode(2,head);
    print(head);

    
    


}