#include <bits/stdc++.h>
#define v 10
using namespace std;

vector<pair<int,int>> graph[v];
vector<bool> vis(v,false);
vector<int> dist(v,INT_MAX);
stack<int> s;

void add_edge(int st,int en, int w,int bi){
    graph[st].push_back(make_pair(en,w));
    if(bi)
        add_edge(en,st,w,false);
}

void print(){
    cout<<"Graph View"<<endl;
    for(int i=0;i<v;i++){
        cout<<i<<" -> ";
        for(int j=0;j<graph[i].size();j++){
            cout<<graph[i][j].first<<"("<<graph[i][j].second<<") -> ";
        }
        cout<<endl;
    }
    cout<<endl;
}
//--------------------------------------------------------
/*
Problem Statement : 
=> Find the shortest path from source to all other nodes in a directed weighted acyclic graph (DAG). 

3 Methods to solve this-
Using Bellman-Ford [ TC = O(VE) ]
Using Dijkstra's Algorithm [ TC = O(V + Elog(V)) ]
Topological Sort [ TC = O(V + E) ]

Algorithm:
1. Find the topological order of the graph and maintain it in a stack. 
2. Initialize all the distance to inf and src to 0; 
3. While stack is empty.Take out the top vertex and update all it's negihbour nodes(only immediate neighbours).
4. do this for all the node in stack which is present in toplogical order. 

Why this is working? 
- In topological sort all the nodes which are reachable from curr node are in the right side and unreachable nodes are in the left.
- So all vertices which form edges with ‘src’ nodes will get updated first. 
Then all the other edges will get relaxed one by one while visiting the vertices in this ordering.

*/
void shortest_path(int src){
    dist[src]=0;
    cout<<"Topologic sort: ";
    while(!s.empty()){
        int top=s.top();
        s.pop();
        cout<<top<<" ";
        if(dist[top]==INT_MAX) 
            continue;
        
        for(int i=0;i<graph[top].size();i++){
            int en=graph[top][i].first;
            int en_w=graph[top][i].second;
            
            if(dist[en]>dist[top]+en_w)
                dist[en]=dist[top]+en_w;
        }
    }
}

void dfs(int ver){
    vis[ver]=true;
    for(int i=0;i<graph[ver].size();i++){
        if(!vis[graph[ver][i].first]){
            dfs(graph[ver][i].first);
        }
    }
    s.push(ver);
}

void topo_sort(){
   // topological sort
    for(int i=0;i<v;i++){
        if(!vis[i])
            dfs(i);
    }
    // while(!s.empty()){
    //     cout<<s.top()<<" ";
    //     s.pop();
    // }
}

int main() {
    
    // undirected acyclic graph
    add_edge(0,1,2,0);
    add_edge(0,4,1,0);
    add_edge(1,2,3,0);
    add_edge(2,3,6,0);
    add_edge(4,2,2,0);
    add_edge(4,5,4,0);
    add_edge(5,3,1,0);
    print();
    topo_sort();
    shortest_path(0);
    cout<<endl<<endl;
    
    for(int i=0;i<v;i++)
        cout<<i<<"("<<dist[i]<<") | ";
    cout<<endl;
    
}




