#include<iostream>
#include<stack>
#include<string>
using namespace std;

//Reverse Stack Using Recursion
//https://www.codingninjas.com/codestudio/problems/reverse-stack-using-recursion_631875?leftPanelTab=0

void insertatbottom(stack<int> &s,int x){
    //insert elment at bootom ka logic
    if (s.empty()) {
    s.push(x);
    return;
  }
  int num = s.top();
  s.pop();
  insertatbottom(s, x);
  s.push(num);
}
void solve(stack<int> &stack){
    //base case 
    if(stack.empty()){
        return;
    }
    int num = stack.top();
    stack.pop();
    //recusive call
    solve(stack);
    insertatbottom(stack,num);
}
void reverseStack(stack<int> &stack) {
    solve(stack);
    
}

int main(){



    


}