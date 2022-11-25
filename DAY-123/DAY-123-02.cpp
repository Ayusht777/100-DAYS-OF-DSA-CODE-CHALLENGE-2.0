#include <bits/stdc++.h> 
#include<stack>
//Delete middle element from stack 
//https://www.codingninjas.com/codestudio/problems/delete-middle-element-from-stack_985246?leftPanelTab=0
using namespace std;

void solve(stack<int>&inputStack,int count,int size){
// base case
    if(count == size/2){
        inputStack.pop();
        return;
    }
    int num = inputStack.top();
    inputStack.pop();
    // recursive call
    solve(inputStack,count+1,size);
    
    inputStack.push(num);
}
void deleteMiddle(stack<int>&inputStack, int N){
    int count = 0;
    solve(inputStack,count,N);
}
int main(){

    
    


}