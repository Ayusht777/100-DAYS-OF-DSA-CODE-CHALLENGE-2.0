#include <iostream>
#include<queue>
using namespace std;
//225. Implement Stack using Queues
//https://leetcode.com/problems/implement-stack-using-queues/description/
// Implement Stack using Queues by making pop() operation costly

class stack {
    //IT will Use 2 Queue 1 for push operation & for pop it will use both 2 queues which will make it as LILO
    // private:
    queue <int> q1,q2;

    public:

    //Memmber functions

    void push(int val){
        q1.push(val);
        //jsut store all elemnt in this stack
    }

    int pop(){
       if(q1.empty())
       {
        // if it will get empty than return -1
        return -1;
       }
       
       while (q1.size()!=1)
       {
          q2.push(q1.front());
          q1.pop();
       }
       // after this loop only one element will be goint to remain which would be last elemen tof this queue

       int temp = q1.front();
       q1.pop();
       // store it and return it

       while (!q2.empty())
       {// swaping this elment and storing in the original queue
         q1.push(q2.front());
         q2.pop();

       }

       return temp;

    }

    int top(){
        if(q1.empty()){
           return -1;
           //no element at top;
        }
        if(q1.size()==1){
            return q1.front();
        }

        while (q1.size()!=1)
       {
          q2.push(q1.front());
          q1.pop();
       }
       // after this loop only one element will be goint to remain which would be last elemen tof this queue

       int temp = q1.front();
       q1.pop();
       // store it and return it

       while (!q2.empty())
       {// swaping this elment and storing in the original queue
         q1.push(q2.front());
         q2.pop();

       }
       q1.push(temp);

       return temp;
        


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
