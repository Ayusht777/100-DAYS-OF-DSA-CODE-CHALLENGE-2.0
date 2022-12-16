#include <bits/stdc++.h>
using namespace std;
//  Merge k sorted lists 
// https://www.codingninjas.com/codestudio/problems/merge-k-sorted-lists_992772?leftPanelTab=0

template <typename T>
    class Node {
        public:
        T data;
        Node* next;

        Node(T data) {
            next = NULL;
            this->data = data;
        }

        ~Node() {
            if (next != NULL) {
                delete next;
            }
        }
    };


class compare{
    public:
    bool operator()(Node<int> * a,Node<int> *b){
        return a -> data > b -> data; 
    }
};
Node<int>* mergeKLists(vector<Node<int>*> &listArray)
{
    priority_queue<Node<int> * ,vector<Node<int>*>,compare> q;
    int k = listArray.size();
    
    if(k == 0){
        return NULL;
    }
    //step 1 : 
    for(int i = 0; i < k ;i++){
        if(listArray[i] != NULL){
            q.push(listArray[i]);
        }
    }
    
    Node<int> * head = NULL;
    Node<int> * tail = NULL;
    
    while(q.size() > 0){
        Node<int> * top = q.top();
        q.pop();
        
        if(top -> next != NULL){
            q.push(top -> next);
        }
        
        if(head == NULL){
            // answer LL is Empty
            head = top;
            tail = top;
        }
        else{
            //insert at linked list
            tail -> next = top;
            tail = top;
        }
        
        
    }
    return head;
    
}
