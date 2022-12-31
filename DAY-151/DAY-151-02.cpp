#include <bits/stdc++.h>
using namespace std;
//Graph : adjacent to list
template<class t>
class graph{
  public:
  unordered_map<t,list<t>> adj;
  void addEdge(int u,int v,bool direction){
    //direction = 0 -> undirected
    //direction = 1 -> directed

    //create an edge from u to v
    adj[u].push_back(v);
    if(direction == 0){
      adj[v].push_back(u);
    }
  }
  void printAdjList(){
    for(auto i : adj){
      cout<<i.first<<" -> ";
      for (auto j : i.second)
      {
        cout<<j<<",";
      }
      cout<<endl;
      
    }
  }

};

int main(){

  int n,m;
  cout<<"enter number of nodes : ";
  cin>>n;
  cout<<"\nenter numbers of edges :";
  cin>>m;
  graph<t> g;
  for (size_t i = 0; i < m; i++)
  {
    int u,v;
    cin>>u>>v;
    g.addEdge(u,v,0);
    //undirected 
  }
  g.printAdjList();

  
}
