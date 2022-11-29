#include <iostream>

using namespace std;
//Implement a Circular Queue 
//https://www.codingninjas.com/codestudio/problems/circular-queue_1170058?leftPanelTab=0

class CircularQueue{
    int *arr;
    int front;
    int rear;
    int size;
    
    public:
   
    CircularQueue(int n){
       arr  = new int [n];
       size =n;
       front = rear =-1;
        
        
       
    }

    
    bool enqueue(int value){
        // to check weather queue  is full 
        if((front==0 && rear == size-1) || (rear == (front-1)%(size-1))){
//             cout<<"Queue is full"<<endl;
            return false;
        }
        else if (front == -1){ //first element  to push
           front = rear =0; 
        }
        else if (rear == size-1 && front != 0){
            rear =0 ;
            //cyclic in nature
            
        }
        else{
            rear++;
        }
        
        arr[rear] =value; //value store karo
        return true;
        
       
    }

    // Dequeues top element from queue. Returns -1 if the stack is empty, otherwise returns the popped element.
    int dequeue(){
         if(front == -1){ //to check queue is empty
//              cout<<"Queue is empty"<<endl;
             return -1;
         }
        int ans =arr[front];
        arr[front] =-1; //ki isko -1 value kardo
        if(front == rear){//single element in queue
            front =rear =-1;
        }
        else if(front == size-1){
            front =0;
            //to maintain cylic oder
            
        }
        else{
            front++;
        }
        return ans;
        
        
    }
};