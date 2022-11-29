#include <bits/stdc++.h>

using namespace std;
//Implementaion Queue using Array
//Implement a Queue 
//https://www.codingninjas.com/codestudio/problems/queue-using-array-or-singly-linked-list_2099908?leftPanelTab=0
//https://www.codingninjas.com/codestudio/problems/queue-using-array-or-singly-linked-list_2099908?leftPanelTab=0
class Queue {
    int *arr;
    int size;
    int qfront;
    int rear;
public:
    Queue() {
       size = 10000;
       arr  =new int[size];
        
        qfront =0;
         rear =0;
        
        
    }

    /*----------------- Public Functions of Queue -----------------*/

    bool isEmpty() {
        if(qfront == rear){
            return true;
            //ki hali hai
        }
        return false;
        
    }

    void enqueue(int data) {
        //push opertion
        
        //
        if(rear==size){
            cout<<"Queue is Full"<<endl;
            
        }
        else{
            arr[rear] = data;
            rear++;
        }
        
    }

    int dequeue() {
        //pop opertion
        
        if(qfront==rear){
            return -1;
            // ki queue khali hai
        }
        else{
            int ans  = arr[qfront];
            arr[qfront] =-1;
            qfront++;
            if(qfront==rear){
                qfront=0;
                rear=0;
                //is sa arrya watse nhi hogi
            }
            return ans;
        }
        
    }

    int front() {
        if(qfront==rear){
            return -1;
            //empty
        }
        else{
            return arr[qfront];
        }
       
    }
};

int main(){
    Queue q;
    q.enqueue(15);

   


   


}
