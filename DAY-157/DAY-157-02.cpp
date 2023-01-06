#include <bits/stdc++.h>
using namespace std;
// Minimum Spanning Tree Using Kruskals 
// https://www.codingninjas.com/codestudio/problems/minimum-spanning-tree_631769?leftPanelTab=0

bool cmp(vector<int> &a,vector<int> &b){
    //it will compare the weight 
    return a[2] < b[2];
}
void makeSet(vector<int> &parent,int n){
    for(int i=0;i<n;i++){
        parent[i] = i;
    }
}
int findParent(vector<int> & parent,int node){
    if(parent[node] == node){
        return node;
    }
    //path compression
    return parent[node] = findParent(parent,parent[node]);
    
}
void unionSet(int u,int v,vector<int> &parent,vector<int> &rank){
    u = findParent(parent,u);
    v = findParent(parent,v);
    
    if(rank[u]<rank[v]){
        parent[u] = v;
    }
    else if(rank[v]<rank[u]){
        parent[v] = u;
    }
    else{
        parent[v] = u;
        rank[u]++;
    }
}
int minimumSpanningTree(vector<vector<int>>& edges, int n)
{  //kruskal algo 
    sort(edges.begin(),edges.end(),cmp);
  vector<int> parent(n);
  //Make a Rank Array with value 0
  vector<int> rank(n,0);
  makeSet(parent,n);
    
   int minWeight = 0;
   
    for(int i=0;i<edges.size();i++){
        int u = findParent(parent,edges[i][0]);
        int v = findParent(parent,edges[i][1]);
        int wt = edges[i][2];
        
        if( u != v){
            minWeight += wt;
            unionSet(u,v,parent,rank);
        }
    }
    
    return minWeight;
}
