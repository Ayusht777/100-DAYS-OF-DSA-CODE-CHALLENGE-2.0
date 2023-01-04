#include <bits/stdc++.h>
using namespace std;
// Shortest path in a directed acyclic graph
// https://www.codingninjas.com/codestudio/library/shortest-path-in-a-directed-acyclic-graph

class Graph{
    public:
    //Make A Adj Adj list with directed and weighted 
    unordered_map<int,set < pair < int,int> > > adj;
    void adjEdge(int u, int v,int weight){
        //The Second Node and THE Weight to it
       pair<int,int> p = make_pair(v,weight); 
       adj[u].insert(p);

    }
    void printg(){
        for(auto i :adj){
            cout<<i.first << " -> ";
            for (auto j : i.second)
            {
                cout<<"[ "<<j.first<<","<<j.second<<" ]"<<",";
            }
            cout<<endl;
            
        }
    }
    void dfs(int node, unordered_map<int,bool> &visited,stack<int> &s){
        visited[node] =true;
        for(auto i : adj[node]){
            if(!visited[i.first]){
                dfs(i.first,visited,s);
            }
        }
        s.push(node);
    }
    void getshortestpath(int src,vector<int>&dist,stack<int> &s){
        dist[src] =0;
        while (!s.empty())
        {
            int top  =s.top();
            s.pop();
            if(dist[top] != INT_MAX){
                for (auto i:adj[top])
                {
                   if(dist[top] + i.second < dist[i.first]){
                    dist[i.first] = dist[top] +i.second;
                   }
                }
                
            }
        }
        

    }


};
int main(){
    Graph g;
    g.adjEdge(0,1,5);
    g.adjEdge(0,2,3);
    g.adjEdge(1,2,2);
    g.adjEdge(1,3,6);
    g.adjEdge(2,3,7);
    g.adjEdge(2,4,4);
    g.adjEdge(2,5,2);
    g.adjEdge(3,4,-1);
    g.adjEdge(4,5,-1);

    //Print The Graph
    g.printg();

    //TopLogical sort
    int n = 6;
    unordered_map<int,bool> visited;
    stack <int> s;
    for (size_t i = 0; i < n; i++)
    {
        if(!visited[i]){
            g.dfs(i,visited,s);
        }
    }

    int src = 1;
    vector<int> dist(n);
    for (int i = 0; i<n; i++)
    {
        dist[i] = INT_MAX;
    }


    g.getshortestpath(src,dist,s);
    
    cout<<"answer is : "<<endl;
    for (int i = 0; i < dist.size(); i++)
    {
       cout<<dist[i] << " ";
    }cout<<endl;
    
    return 0;

}