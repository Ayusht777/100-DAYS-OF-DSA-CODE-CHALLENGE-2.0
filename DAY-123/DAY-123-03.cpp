#include <bits/stdc++.h> 
#include<stack>
// Valid Parentheses 
//https://www.codingninjas.com/codestudio/problems/valid-parenthesis_795104?leftPanelTab=0
using namespace std;

bool isValidParenthesis(string expression) {
  stack < char > s;
  for (int i = 0; i < expression.length(); i++) {
    char ch = expression[i];
    if (ch == '(' || ch == '{' || ch == '[') {
      s.push(ch);

    } else {
      //for closing braking

      if (!s.empty()) {
        char top = s.top();
        if ((ch == ')' && top == '(') ||
          (ch == '}' && top == '{') ||
          (ch == ']' && top == '[')
        ) {
          s.pop();

        } else {
          return false;
        }
      } else {
        return false;
      }

    }

  }

  if (s.empty()) {
    return true;
  } else {
    return false;
  }

}
int main(){

    
    


}