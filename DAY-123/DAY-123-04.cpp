#include <bits/stdc++.h> 
#include<stack>
// Insert An Element At Its Bottom In A Given Stack 
//https://www.codingninjas.com/codestudio/problems/insert-an-element-at-its-bottom-in-a-given-stack_1171166?leftPanelTab=0
using namespace std;
#include <bits/stdc++.h>

void solve(stack < int > & s, int x) {
  //base case
  if (s.empty()) {
    s.push(x);
    return;
  }
  int num = s.top();
  s.pop();
  solve(s, x);
  s.push(num);
}
stack < int > pushAtBottom(stack < int > & myStack, int x) {
  solve(myStack, x);
  return myStack;

}
int main(){

    
    


}