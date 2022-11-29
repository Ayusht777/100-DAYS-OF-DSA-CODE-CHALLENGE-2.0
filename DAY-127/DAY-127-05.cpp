#include <iostream>
#include<deque>
using namespace std;
//dequeu

int  main(){
    deque <int> d;
    d.push_front(10);
    cout<<d.front()<<endl;
    d.push_front(11);
    cout<<d.front()<<endl;
    d.push_front(12);
    cout<<d.front()<<endl;
    d.push_front(13);
    cout<<d.front()<<endl;
    d.push_back(14);
    cout<<d.front()<<endl;
    d.push_back(15);
    cout<<d.front()<<endl;
    d.pop_front();
    d.pop_back();
    cout<<d.front()<<endl;
    cout<<d.size()<<endl;
    


}