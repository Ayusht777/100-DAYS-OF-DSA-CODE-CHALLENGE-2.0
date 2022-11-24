#include<iostream>

using namespace std;

//Impelmentation of stack using array

class stack{
    //properties
    public:
    int top;
    int * arr;
    int size;
    
    /// constructor

    stack(){
       


    }

    //operations

    void push(int element){
        // matlab ek elemnt ki jaga ha
        if(size-top>1){
            arr[++top] =element;

        }
        else{
            cout<<"stack overflow"<<endl;
        }

    }

    void pop(){
        if(top>=0){

            top--;
        }
        else{
            cout<<"stack is underflow"<<endl;
        }

    }

    int peek(){
        if(top>=0 && top<= size){
            return arr[top];
        }
        else{
           cout<<"stack is empty"<<endl;
           return -1;
        }

    }

    bool isempty(){
        if(top==-1){
            return true;
        }
        else{
            return false;
        }

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
   
   if(s.isempty()){
    cout<<"not empty"<<endl;
   }
   else{
    cout<<"empty"<<endl;
   }




}