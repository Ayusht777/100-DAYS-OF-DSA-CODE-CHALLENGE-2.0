#include <bits/stdc++.h>
using namespace std;
// Shortest path in an unweighted graph 
// https://www.codingninjas.com/codestudio/problems/shortest-path-in-an-unweighted-graph_981297?leftPanelTab=0
vector<int> shortestPath( vector<pair<int,int>> edges , int n , int m, int s , int t){
   //Creeta adj list
    unordered_map<int,list<int>> adj;
    for(int i = 0;i<m;i++){
        int u = edges[i].first;
        int v = edges[i].second;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    //do Bfs
    unordered_map<int,bool> visited;
    unordered_map<int,int> parent;
    queue<int> q;
    q.push(s);//s is sourec node
    parent[s] = -1;
    visited[s] =true;
    
    while(!q.empty()){
        int front = q.front();
        q.pop();
        for(auto i :adj[front]){
            if(!visited[i]){
            visited[i] = true;
            parent[i] =front;
            q.push(i);
            }
        }
    }
    //perpare shortets path
    vector<int> ans;
    int currNode =t; //last Node
    ans.push_back(currNode);
    
    while(currNode != s){
        currNode =parent[currNode];
        ans.push_back(currNode);
    }
    reverse(ans.begin(),ans.end());
    return ans;
}
