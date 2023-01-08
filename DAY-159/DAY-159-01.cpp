#include <bits/stdc++.h>
using namespace std;
//  Count Strongly Connected Components (Kosaraju’s Algorithm) 
// https://www.codingninjas.com/codestudio/problems/count-strongly-connected-components-kosaraju-s-algorithm_1171151?leftPanelTab=0
void dfs(int node,unordered_map<int,bool> &vis,stack<int> &st, unordered_map<int,list<int>> &adj){
    vis[node] = true;
    for(auto nb : adj[node]){
       if(!vis[nb]){
           dfs(nb,vis,st,adj);
       } 
    }
    //store this in stack
    st.push(node);
}
void ndfs(int node,unordered_map<int,bool> &vis,unordered_map<int,list<int>> &adj){
    vis[node] = true;
    for(auto nb : adj[node]){
       if(!vis[nb]){
           ndfs(nb,vis,adj);
       } 
    }
    
}
int stronglyConnectedComponents(int v, vector<vector<int>> &edges)
{
    unordered_map<int,list<int>> adj;
	//find ADJ list
    for(int i =0;i<edges.size();i++){
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u].push_back(v);
    }
    //TopLogical sort
    stack<int> st;
    unordered_map<int,bool> vis;
    for(int i =0;i<v;i++){
        if(!vis[i]){
            dfs(i,vis,st,adj);
        }
    }
    //transpose graph
    unordered_map<int,list<int>> trans;
    for(int i= 0;i<v;i++){
        vis[i] = 0;
        for(auto nb : adj[i]){
            trans[nb].push_back(i);
        }
    }
    //dfs call using above ordering
    int count =0;
    while(!st.empty()){
        int top = st.top();
        st.pop();
        if(!vis[top]){
            count++;
            ndfs(top,vis,trans);
        }
    }
    return count;
    
}