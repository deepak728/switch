#include <bits/stdc++.h>
#define v 6
using namespace std;

vector<pair<int,int>> graph[v+1];
vector<bool> vis(v+1,false);

void add_edge(int st,int en, int w,int bi){
    graph[st].push_back(make_pair(en,w));
    if(bi) add_edge(en,st,w,false);
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
    cout<<endl<<endl;
}

void dfs(int ver,stack<int> &s){
    vis[ver]=true;
    int prev=ver;
    for(int i=0;i<graph[ver].size();i++){
        if(!vis[graph[ver][i].first]){
            dfs(graph[ver][i].first,s);
        }
            
    }
    s.push(ver);
}

void topo_sort(){
   // topological sort
    stack<int> s;
    for(int i=0;i<v;i++){
        if(!vis[i])
            dfs(i,s);
    }
    
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
    cout<<endl<<endl;
}

int main() {
    
    // undirected acyclic graph
    add_edge(5,0,4,0);
    add_edge(5,2,8,0);
    add_edge(2,3,11,0);
    add_edge(3,1,8,0);
    add_edge(4,0,7,0);
    add_edge(4,1,2,0);
    print();
    topo_sort();
}