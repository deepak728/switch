#include <bits/stdc++.h>
#define v 9
using namespace std;


vector<pair<int,int> > graph[v]; // A 2D vector to represent graph as adjacency list; 1.end node, 2.weight
vector<bool> vis(v,0); // visited array

void add_edge(int st,int en,int w, bool bi){
    graph[st].push_back(make_pair(en,w));
    if(bi) add_edge(en,st,w,false);
}

void print(){
    cout<<"Graph View"<<endl;
    for(int i=0;i<v;i++){
        cout<<i<<" -> ";
        for(int j=0;j<graph[i].size();j++)
            cout<<graph[i][j].first<<"("<<graph[i][j].second<<") -> ";
        cout<<endl;
    }
    cout<<endl;
}

void dfs_rec(int ver){
    vis[ver]=true;
    cout<<ver<<" ";
    for(int i=0;i<graph[ver].size();i++){
        if(!vis[graph[ver][i].first]){
            vis[graph[ver][i].first]=true;
            dfs_rec(graph[ver][i].first);
        }
            
    }
}

void dfs(){
    cout<<"DFS Traversal "<<endl;
    vis.resize(0);
    vis.resize(v,0);
    for(int i=0;i<v;i++){
        if(!vis[i])
            dfs_rec(i);
    }
        
    cout<<endl<<endl;
}

void bfs(){
    cout<<"BFS traversal"<<endl;
    vis.resize(0);
    vis.resize(v,0);
    queue<int> q;
    for(int i=0;i<v;i++){
        if(!vis[i]){
            q.push(i);
            vis[i]=true;
            while(!q.empty()){
                int curr=q.front();
                q.pop();
                cout<<curr<<" ";
                for(int j=0;j<graph[curr].size();j++){
                    if(!vis[graph[curr][j].first]){
                        vis[graph[curr][j].first]=true;
                        q.push(graph[curr][j].first);
                    }
                }
            }
        }
    }
    cout<<endl<<endl;
}

int main() {
    add_edge(0,1,4,1);
    add_edge(0,7,8,1);
    add_edge(1,7,11,1);
    add_edge(1,2,8,1);
    add_edge(2,3,7,1);
    add_edge(2,8,2,1);
    add_edge(3,4,9,1);
    add_edge(3,5,14,1);
    add_edge(4,5,10,1);
    add_edge(5,6,2,1);
    add_edge(6,7,1,1);
    add_edge(6,8,6,1);
    add_edge(7,8,7,1);
    print();
    dfs();
    bfs();
}