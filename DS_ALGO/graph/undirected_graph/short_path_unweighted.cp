#include <bits/stdc++.h>
#define v 10
using namespace std;

vector<int> graph[v]; // A 2D vector to represent graph as adjacency list; 1.end node
vector<int> spgraph[v]; // A 2D vector to represent an unweighted graph. 
vector<bool> vis(v,0); // visited array
vector<int> dist(v,INT_MAX); // distance from source to all other nodes, src =0 ;

void add_edge(int st,int en, bool bi){
    graph[st].push_back(en);
    if(bi) add_edge(en,st,false);
}

void add_edge_sp(int st,int en,bool bi){
    spgraph[st].push_back(en);
    if(bi)
        spgraph[en].push_back(st);
}

void print(){
    cout<<"UnWeighted Graph View"<<endl;
    for(int i=0;i<v;i++){
        cout<<i<<" -> ";
        for(int j=0;j<graph[i].size();j++)
            cout<<graph[i][j]<<" -> ";
        cout<<endl;
    }
    cout<<endl;
}

//--------------------------------------------------------------------
/* Algorithm: 
1. BFS can be used to find the shortest path from source to all the other nodes in case of unweighted graph or same weighted graph. 
Because BFS bfs traverse level wise. We node it visits will be at the minimum distance from source. 
2. If there is any path which is shorted than the curr dist then update the distance and push it to queue. (There will be only one
updatation for each node because in it's first iteration bfs will give the shortest path from source to that node)
3. To find all the paths from source to destination create a new directed graph where whenever there is an updation or same dist
path is available connect a directed edge between curr node to neighbour node. 
4. Apply dfs at the end which leads to the destination and print all the paths. 

TC: It has a time complexity of BFS algo O(E+V);

Note :
1. DFS cannot be used because dfs will traverse depth first and even if it reaches destination it's not guranteed that it will the
sortest path. 
2. Printing all the shortest path using above algo will not work for weighted graph because in that it's not guaranteed that 
bfs or dijkstra will give the shortest path in it's first iteration itself.
*/

void dfs(int curr,int dest,vector<int> &temp){
    temp.push_back(curr);
    if(curr==dest){
        for(int i=0;i<temp.size();i++)
            cout<<temp[i]<<"->";
        cout<<endl;
    }
    
    for(int i=0;i<spgraph[curr].size();i++){
        int en=spgraph[curr][i];
        dfs(en,dest,temp);
    }
    temp.pop_back();
}

void print_sp(int src,int dest){
    vector<int> temp;
    cout<<"All shortest path from source to destination : "<<endl;
    dfs(src,dest,temp);
}

void spath(int src,int dest){ 
  
  queue<int> q;
  q.push(src);
  dist[src]=0;
  while(!q.empty()){
      int top=q.front();
      q.pop();
      
      for(int i=0;i<graph[top].size();i++){
          int en=graph[top][i];
          if(dist[en]>dist[top]+1){
              dist[en]=dist[top]+1;
              q.push(en);
              add_edge_sp(top,en,0);
          }else if (dist[en]==dist[top]+1)
             add_edge_sp(top,en,0);
          else
            continue;
      }
  }
}

int main() {
    /* Problem Statement : 
    1. In an undirected unweighted graph find the shortest distance from source to all other nodes. 
    2. Print all the shortest path from the given source to destination. 
    */
    
    add_edge(0,1,1);
    add_edge(1,2,1);
    add_edge(1,3,1);
    add_edge(1,4,1);
    add_edge(2,5,1);
    add_edge(3,5,1);
    add_edge(4,6,1);
    add_edge(5,8,1);
    add_edge(6,7,1);
    add_edge(6,8,1);
    add_edge(7,8,1);
    print();
    spath(0,8);
    
    print_sp(0,8);
    cout<<endl<<endl;
    cout<<"Shortest distance from source to all other nodes : "<<endl;
    for(int i=0;i<v;i++){
        cout<<i<<" ("<<dist[i]<<") |"<<" ";
    }
    
}


