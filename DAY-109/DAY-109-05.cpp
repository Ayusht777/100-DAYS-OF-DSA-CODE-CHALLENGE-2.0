
#include <bits/stdc++.h> 

using namespace std;
//509. Fibonacci Number

//https://leetcode.com/problems/fibonacci-number/description/

 int fib(int n) {
        if(n==0){
            return 0;
        }
        if(n==1){
            return 1;
        }

        return (fib(n-1) + fib(n-2));
    }

int main(){
    //factorila using recusrion
   for(int i=0;i<10;i++){
    cout<<fib(i)<<" ";
   }


}