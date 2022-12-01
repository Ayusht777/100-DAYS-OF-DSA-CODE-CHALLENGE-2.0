#include <iostream>
#include<queue>
using namespace std;
//Implement Stack using Only 1 Queues


class stack {
    
    queue <int> q1;

    public:

    //Memmber functions

    void push(int val){
        int qsize = q1.size();

        //push this elemnet
        q1.push(val);

        for(int i=0;i<qsize;i++){
            ///make copy of the current element
            q1.push(q1.front());
            q1.pop();
            // Delete front element
        }

    }

    int pop(){
      if(q1.empty()){
        return -1;
      }
      else{
        int temp =q1.front();
        q1.pop();
      return temp;
      }

    }

    int top(){
       if(q1.empty()){
        return -1;
      } 
      return q1.front();

    }

    int size(){
        return q1.size();

    }



};

int main(){
    stack s1;
    s1.push(1);
    s1.push(2);
    s1.push(3);
    s1.push(4);
    cout<<s1.size()<<endl;
    cout<<s1.top()<<endl;
    s1.pop();
    cout<<s1.top()<<endl;
    cout<<s1.size()<<endl;

}
