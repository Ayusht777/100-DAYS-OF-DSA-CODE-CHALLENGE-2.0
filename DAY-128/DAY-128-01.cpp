#include <bits/stdc++.h>
#include<queue>
using namespace std;

//Queue Reversal
// using itertive solution
//https://practice.geeksforgeeks.org/problems/queue-reversal/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article
queue<int> rev(queue<int> q)
{
    stack <int> s;
    
    while(!q.empty()){
        s.push(q.front());
        q.pop();
    }
    
    while(!s.empty()){
        q.push(s.top());
        s.pop();
    }
    
   
    
    
    return q;
}
int main()
{
    int test;
    cin>>test; 
    while(test--)
    {
    queue<int> q; 
    int n, var; 
    cin>>n; 
    while(n--)
    {
        cin>>var; 
        q.push(var);
    }
    queue<int> a=rev(q); 
    while(!a.empty())
    {
        cout<<a.front()<<" ";
        a.pop();
    }
    cout<<endl; 
    }
}
