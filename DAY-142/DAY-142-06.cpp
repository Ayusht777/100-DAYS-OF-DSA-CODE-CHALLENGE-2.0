#include <bits/stdc++.h>
//use queue
using namespace std;
//Priority Queue

int main(){
    //by default max heap
    priority_queue<int> p;
    p.push(50);
    p.push(20);
    p.push(10);
    p.push(30);
    p.push(40);

    cout<<"element at top : "<<p.top()<<endl;
    cout<<"Size : "<<p.size()<<endl;
    p.pop();
    cout<<"element at top : "<<p.top()<<endl;
    cout<<"Size : "<<p.size()<<endl;
    cout<<"-----------------------------------------------"<<endl;
    //min heap
    priority_queue<int,vector<int>,greater<int> > q;
    q.push(50);
    q.push(20);
    q.push(10);
    q.push(30);
    q.push(40);

    cout<<"element at top : "<<q.top()<<endl;
    cout<<"Size : "<<q.size()<<endl;
    q.pop();
    cout<<"element at top : "<<q.top()<<endl;
    cout<<"Size : "<<q.size()<<endl;

    

}
