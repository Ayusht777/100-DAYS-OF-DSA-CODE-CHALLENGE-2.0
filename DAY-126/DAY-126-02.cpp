#include <bits/stdc++.h>
using namespace std;


#include<stack>
// Design a stack that supports getMin() in O(1) time and O(1) extra space 
//https://www.codingninjas.com/codestudio/problems/design-a-stack-that-supports-getmin-in-o-1-time-and-o-1-extra-space_842465?leftPanelTab=0
class SpecialStack {
    // Define the data members.
    stack<int>s;
    int mini;

    /*----------------- Public Functions of SpecialStack -----------------*/
    public:
        
    void push(int data) {
        if(s.empty()){
            s.push(data);
            mini = data;
        }
        else{
            if(data < mini){
                s.push(2*data-mini);
                mini = data;
            }
            else{
                s.push(data);
            }
        }
    }

    int pop() {
        if(s.empty())
            return -1;
        
        int curr = s.top();
        s.pop();
        
        if(curr > mini){
            return curr;
        }
        else{
            int prevMini = mini;
            int val = 2*mini-curr;
            mini = val;
            
            return prevMini;
        }
    }

    int top() {
        
        if(s.empty())
            return -1;
        
        int curr = s.top();
        
        if(curr < mini)
            return mini;
        else
            return curr;
    }

    bool isEmpty() {
        return s.empty();
    }

    int getMin() {
        
        if(s.empty())
            return -1;
        
        return mini;
    }  
};

