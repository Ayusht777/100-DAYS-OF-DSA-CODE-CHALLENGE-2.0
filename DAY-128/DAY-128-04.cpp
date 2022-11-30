#include <bits/stdc++.h>

using namespace std;
//Reverse First K elements of Queue
//https://practice.geeksforgeeks.org/problems/reverse-first-k-elements-of-queue/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article

queue<int> modifyQueue(queue<int> q, int k) {
    // stack where we put all k element
    stack<int> s;
    // step 1 : pop first k form Q and put into stack
    for (int i = 0; i < k; i++) {
        s.push(q.front());
        q.pop();
    }
    // step 2 : fetch element form stack and put in queue

    while (!s.empty()) {
        q.push(s.top());
        s.pop();
    }

    // Step  3 put the remaing or sattring elment in que to orignal palce

    for (int i = 0; i < q.size() - k; i++) {
        q.push(q.front());
        q.pop();
    }

    return q;
}

queue<int> modifyQueue(queue<int> q, int k);
int main() {
    int t;
    cin >> t;
    while (t-- > 0) {
        int n, k;
        cin >> n >> k;
        queue<int> q;
        while (n-- > 0) {
            int a;
            cin >> a;
            q.push(a);
        }
        queue<int> ans = modifyQueue(q, k);
        while (!ans.empty()) {
            int a = ans.front();
            ans.pop();
            cout << a << " ";
        }
        cout << endl;
    }
}