#include <iostream>

using namespace std;
//Implement a Queue Linkedlist

class Node {

    public:

    int d;
    Node * next;
    //consyructor
    Node(int d) {
        this -> d = d;
        this -> next = NULL;
    }

};

class Queue {
    private:
    Node * front, * rear;
    public:

        //consrtcur of queue

        Queue() {
            front = rear = NULL;

        }

    //fiunction

    void enqeue(int data) {
        //push function
        Node * temp = new Node(data);
        if (rear == NULL) {
            front = rear = temp;
            //iska matlab ha rera aur front ko temp pa,point karrha hai

        } else {

            rear -> next = temp;
            //aur new node ha joki rear temp ma poimt hai
            //aur rear ko move akrna pdaga

            rear = temp;

        }
    }

    int deqeue() {
        if (front == NULL) {

            return -1;

            // ki pop ka sa karyga
        } else {
            Node * temp = front; //kyui kiis pointer ko frre karga
            front = front -> next;
            if (front == NULL) {//ek hi node hai 
                rear = NULL;
            }
            int ans = temp -> d;
            delete temp;
            return ans;

        }

    }
    int front(){
        if(front==NULL){
            return -1;
        }
        return front->d;

    }
    bool isEmpty(){
        return (front == NULL && rear == NULL);
    }

    void print() {

        if (front == NULL) {
            cout << "queue is empty" << endl;
        } else {
            Node * temp = front;

            while (temp != NULL) {
                cout << temp -> d << endl;
                temp = temp -> next;
            }

        }

    }

};

int main() {
    Queue q;
    q.print();

    q.enqeue(155);

    q.enqeue(156);

    q.enqeue(158);

    q.enqeue(159);

    q.print();
    q.deqeue();
    q.print();

}