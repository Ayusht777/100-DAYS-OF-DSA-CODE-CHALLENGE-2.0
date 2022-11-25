#include<iostream>
#include<stack>
#include<string>
using namespace std;

//Reverse a string using Stack
//https://practice.geeksforgeeks.org/problems/reverse-a-string-using-stack/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article
int main(){

    string name = "ayush";
    stack <char> stacked;
    string ans = ""; //empyt string
    for(int i=0;i<name.length();i++){
        stacked.push(name[i]);

        // stack ma element dalat
    }
    

    ///check stack is not empty loop
    while (!stacked.empty()) 
    {
         ans.push_back(stacked.top());
         stacked.pop();//emoyt this stack 
    }

    cout<<"The answer in Reverse : "<<ans<<endl;

    


}