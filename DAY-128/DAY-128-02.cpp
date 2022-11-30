#include <bits/stdc++.h>
#include<queue>
using namespace std;

//Queue Reversal
// using recursive solution
//https://practice.geeksforgeeks.org/problems/queue-reversal/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article
void reverseq(queue<int>& q) {
    // base case
    if (q.size() == 0) {
        return;
    }

    int store_variable = q.front();
    // pop this queue for next call

    q.pop();

    // asking recursion to reverse the
    // leftover queue
    reverseq(q);

    q.push(store_variable);
}
queue<int> rev(queue<int> q) {
    reverseq(q);
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
