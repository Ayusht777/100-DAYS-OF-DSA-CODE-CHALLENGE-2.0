#include <bits/stdc++.h> 
using namespace std;
//Check if Linklist is circular or not
//CircularLinedklist

class Node{

    public:

    int data;
    Node *next ; 
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

void insertatnode(Node * &tail,int element ,int d){
    //empyt list
    if(tail==NULL){
        Node * temp = new Node(d);
        tail = temp;
        temp->next = temp;
    }

    else{
        //npn empty list
        //assum that element is presnet in list

        Node *curr =tail;
        while (curr->data!=element)
        {
            curr = curr->next;
        }
        //elemnt found
         Node * temp = new Node(d);
         temp->next =curr->next;
         curr->next=temp;

        
    }
}

void print(Node * &tail){

    Node *temp = tail;
    if(tail==NULL){
        cout<<"list is empty"<<endl;
    }
    do
    {
        cout<<tail->data<<" ";
        tail = tail->next; 
    } while (tail!=temp);
cout<<endl;

}

void deletenode(Node * &tail,int element ){
    //empty list
    if(tail==NULL){
        cout<<"you are trying to delete a empty list"<<endl;
        return;
    }

    else{
        //non empty
        //assumming that 'value' is persent
        Node *prev =tail;
        Node *curr = prev->next;
        while (curr->data!= element)
        {
           prev->next =curr->next;
          curr=curr->next;
        }
        prev->next =curr->next;
        // node case
        if(curr==prev){
            tail =NULL;
        }
        //node 2>= 
        else  if(tail==curr){
            tail=prev;
        }
        curr->next =NULL;
        delete curr;
        
    }


}

bool isCircularlist(Node * head){
    if(head==NULL){
        return true;
    }

   Node * temp =head->next;
   while (temp!=NULL&&temp!=head)
   {
     temp = temp->next;
   }
   if(temp==head){
    return true;
    //circular ha 
   }
   return false;

}

int main(){
    Node *tail =NULL;
     Node *tail1 =NULL;
    insertatnode(tail,7,48);
    insertatnode(tail,48,49);
    insertatnode(tail,48,40);
     insertatnode(tail1,7,48);
    print(tail);
   if(isCircularlist(tail)){
    cout<<"list is circular"<<endl;
   }
   else{
    cout<<"not circular in nature"<<endl;
   }
   print(tail1); 
   if(isCircularlist(tail1)){
    cout<<"list is circular"<<endl;
   }
   else{
    cout<<"not circular in nature"<<endl;
   }


}
