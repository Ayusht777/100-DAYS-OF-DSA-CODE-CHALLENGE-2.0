#include <bits/stdc++.h>
using namespace std;

//N Stacks In An Array 
//https://www.codingninjas.com/codestudio/problems/n-stacks-in-an-array_1164271
class NStack {

  int * arr;
  int * top;
  int * next;

  int n, s;
  int freespot;

  public:
    // Initialize your data structure.
    NStack(int N, int S) {
      n = N; //n is numbers of stack 
      s = S; // size of an array
      arr = new int[s];
      top = new int[n];
      next = new int[s];

      // for loop to inzitalze all value of top to -1

      for (int i = 0; i < n; i++) {
        top[i] = -1;

      }

      // next ko inzitalize

      for (int i = 0; i < s; i++) {
        next[i] = i + 1; // i = i+1 == 0 = 1;

      }
      // next ki last value to -1;

      next[s - 1] = -1;

      freespot = 0;

    }

  // Pushes 'X' into the Mth stack. Returns true if it gets pushed into the stack, and false otherwise.
  bool push(int x, int m) {
    // check karo ki stack overflow toh nhi hai

    if (freespot == -1) {
      return false;
    }
    //find index = i
    int i = freespot;

    //freespot ko update karna hai

    freespot = next[i];
    //insert elemnt into array

    arr[i] = x;

    //update next

    next[i] = top[m - 1]; //iska mtlb ki  m = is stake ka index 
    // so fisrt stack  = 1 -> 1-1 = 0 top[0] value  -1 woh next[i] -> 
    // next[0] = -1// matlbha yeh spaec bhara huwe hai

    // top ko update kar do

    top[m - 1] = i;
    // m = 1 -> 1-1 = 0 ->> top[0] = 0 ha ;
    // iska matlab hai ki stake ma ek elment agya hai

    return true;

  }

  // Pops top element from Mth Stack. Returns -1 if the stack is empty, otherwise returns the popped element.
  int pop(int m) {
    // check underflow 
    if (top[m - 1] == -1) {
      return -1;

      // iska matlab ha  ki stack ka top -1 ha toh empty hai
    }

    // revrse of push logic

    int i = top[m - 1];

    top[m - 1] = next[i];
    next[i] = freespot;
    freespot = i;

    return arr[i];

  }
};

int main(){
    int n = 2 ; //2 stack
    int s = 5; // 5 szie h array
    NStack x(n,s);
    cout<<x.push(11,1)<<endl;
    cout<<x.push(11,1)<<endl;
    cout<<x.push(11,1)<<endl;
    cout<<x.push(11,1)<<endl;
    cout<<x.push(11,2)<<endl;
    

}