#include <bits/stdc++.h>
using namespace std;
// Prim's MST 
// https://www.codingninjas.com/codestudio/problems/prim-s-mst_1095633?leftPanelTab=0
vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g)
{
   //create adj list
  unordered_map<int,list<pair <int,int> > >adj;
   for(int i = 0; i < g.size(); i++){
      int u = g[i].first.first; //g[i][0][0];
      int v = g[i].first.second;//g[i][0][1];
      int w = g[i].second;
      adj[u].push_back(make_pair(v,w));
      adj[v].push_back(make_pair(u,w));
   }
    vector<int> key(n+1,INT_MAX);
    //Key array With n+1 size and indexing will be one base
    vector<bool> mst(n+1,false);
    //mst track 
    vector<int> parent(n+1,-1);
    // parent array with index
    //first node ka distance 0
    key[1] = 0;
    
  for(int i = 1;i<n;i++){
      int mini = INT_MAX;
      int u;
      //find the min value
      for(int j = 1;j<=n;j++){
          if(mst[j] == false && key[j] < mini){
              u= j;
              mini = key[j];
          }
      }
          //mark min node as true
    mst[u] = true;
    
    //check its adjacent nodes
    for(auto i : adj[u]){
        int v = i.first;
        int w = i.second;
        if(mst[v] == false && w < key[v]){
            parent[v] = u;
            key[v] = w;
        }
    }
  }

    
    vector<pair<pair<int, int>, int>> result;
    //0 node nhi hai and 1 = - 1 so start with 2
    for(int i = 2;i<=n;i++){
        result.push_back({{parent[i],i},key[i]});
    }
    return result;
    
}
