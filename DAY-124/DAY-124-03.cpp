#include<iostream>
#include<stack>
#include<string>
using namespace std;
// Redundant Brackets 
// https://www.codingninjas.com/codestudio/problems/redundant-brackets_975473?leftPanelTab=0

bool findRedundantBrackets(string &s)
{
    stack <char> st;
    //loop
    for(int i=0;i<s.length();i++){
        char ch = s[i];
        if(ch=='(' || ch== '+' || ch== '-' || ch== '*'|| ch== '/'){
            st.push(ch);
        }
        else{
            //colsing barck 
            if(ch == ')'){
                bool isRedundant =true;
                
                while(st.top()!='('){
                    char top =st.top();
                    if(top=='+'||top=='-'||top=='*'||top=='/'){
                       isRedundant = false;
                        //ki yeh redunt nhi hai
                    }
                    st.pop();
                }
              
                if(isRedundant ==true){
                    return true;
                }
                
                st.pop();
                
                
            }
        }
    }
    
    return false;
    
  
}


int main(){



    


}