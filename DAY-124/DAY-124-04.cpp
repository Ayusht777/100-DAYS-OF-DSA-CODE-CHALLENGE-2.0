#include<iostream>
#include<stack>
#include<string>
using namespace std;
// Minimum Cost To Make String Valid 
//https://www.codingninjas.com/codestudio/problems/minimum-cost-to-make-string-valid_1115770?leftPanelTab=0
#include <bits/stdc++.h> 
#include<stack>
int findMinimumCost(string str) {
  
    //odd conditon 
    if(str.length()%2==1){
        return -1;
    }
    stack <char> s;
    for(int  i= 0;i<str.length();i++){
        char ch = str[i];
        if(ch == '{'){
            s.push(ch);       
        }
        
        else{
            //ch is closing bracket
            if(!s.empty() && s.top() =='{'){
                s.pop();
            }
            else{
                s.push(ch);
            }
        }
        
    }
    // stack opertaions
     int a =0,b=0;
    while(!s.empty()){
        if(s.top() == '{'){
            b++;
        }
        else{
            a++;
        }
        s.pop();
    }
    int ans =(a+1)/2 + (b+1)/2;
    
    return ans;
}

int main(){



    


}