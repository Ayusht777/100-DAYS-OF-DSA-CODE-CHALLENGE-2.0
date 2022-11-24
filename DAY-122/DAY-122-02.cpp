#include<iostream>

using namespace std;

//Impelmentation of stack using linklist
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

    // ~Node(){
    //     int value  = this->data;
    //     //memory free

    //     if(this->next!=NULL){
    //         delete next;
    //         this->next = NULL;
    //     }

    //     cout<<"Memory free "<<value<<endl;
    // }


};

class stack{
    Node * top;
    //properties
    public:
    
    
    /// constructor

    stack(){
        top ==NULL;


        


    }

    //operations

    void push(int element){
     Node *temp = new Node(element);

     if(!temp){
        cout<<"stack overflow"<<endl;
        exit(1);
     }

     temp->data =element;
     temp->next =top;

     temp =top;

        
    }

    void pop(){

        Node * temp;

        if(top==NULL){
            cout<<"stack is empty"<<endl;
        }

        else{
            temp =top;
            top =top->next;

            free(temp);
        }

        

    }

    int peek(){
        if(top==NULL){
            return true;
        }
        else{
            return false;
        }
        

    }

    bool isEmpty()
   {

return top == NULL;
    }



};

int main(){
   
  stack s ;
    s.push(5);
    s.push(10);
    s.push(12);
    s.push(11);
    
    
    cout<<s.peek()<<endl;

    s.pop();
   
    cout<<s.peek()<<endl;
   
   




}