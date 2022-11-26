#include<iostream>
#include<stack>
#include<string>
using namespace std;
//Sort a Stack 
//https://www.codingninjas.com/codestudio/problems/sort-a-stack_985275?leftPanelTab=0
void sortedinsert(stack<int> &s,int num){
    //baese case
    if(s.empty()||(s.top()<num)){
        s.push(num);
        return;
        
    }
    int n = s.top();
    s.pop();
    //recursive call
    sortedinsert(s,num);
    s.push(n);
    
}
    

void sortStack(stack<int> &stack)
{
	//base case 
    if(stack.empty()){
        return;
    }
    int num = stack.top();
    stack.pop();
    //recusrive call
    
    sortStack(stack);
    
    sortedinsert(stack,num);
}

int main(){



    


}