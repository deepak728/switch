#include <bits/stdc++.h>
#define v 10
using namespace std;

vector<pair<int,int>> graph[v+1];
vector<bool> vis(v+1,false);
vector<bool> rec(v+1,false);

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


// ------------UNDIRECTED____________
/*Algo 
1. Do normal dfs. 
2. if and visted node is encountered and it's not the parent node then graph is cyclic.
*/


bool dfs_undirected(int ver,int par){
    vis[ver]=true;
    bool ans=0;
    for(int i=0;i<graph[ver].size();i++){
        int en=graph[ver][i].first;
        if(vis[en]){
            if(en!=par)
                return true;
        }else
            ans|=dfs_undirected(en,ver);
    }
    return ans;
}

bool detect_cycle_undirected(){ //detect cycle in an undirected graph
    vis.resize(0);
    vis.resize(v+1,false);
    bool ans=false;
    for(int i=0;i<v;i++){
        if(!vis[i]){
            ans|=dfs_undirected(i,-1);
        }
    }
    return ans;
}

//_________________DIRECTED_____________________
/*
1. Do normal dfs. Create a visited and rec array (which will indicate if that node is in recrsive stack or not)
2. If any node is encountered which is present in the recursive stack means the graph is cyclic. 
3. Take the node out from the recurisve stack after visiting all it's neighbours.
*/

bool dfs_directed(int ver){
    vis[ver]=true;
    rec[ver]=true;
    bool ans=0;
    for(int i=0;i<graph[ver].size();i++){
        int en=graph[ver][i].first;
        if(rec[en]){
                return true;
        }
        if(!vis[en])
            ans|=dfs_directed(en);
    }
    rec[ver]=false;
    return ans;
}

bool detect_cycle_directed(){ //detect cycle in an undirected graph
    vis.resize(0);
    vis.resize(v+1,false);
    bool ans=false;
    for(int i=0;i<v;i++){
        if(!vis[i]){
            ans|=dfs_directed(i);
        }
    }
    return ans;
}

int main() {
    
    // // undirected graph
    // add_edge(0,1,1,1);
    // add_edge(0,2,1,1);
    // add_edge(0,3,1,1);
    // add_edge(1,2,1,1);
    // add_edge(3,4,1,1);
    // add_edge(5,6,1,1);
    // add_edge(5,7,1,1);
    // add_edge(5,5,1,1);
    // add_edge(6,7,1,1);
    // print();
    // cout<<" Is Undirected graph cyclic : "<<detect_cycle_undirected()<<endl;
    
    // directed graph
    add_edge(0,1,1,0);
    add_edge(1,2,1,0);
    add_edge(2,0,1,0);
    add_edge(0,3,1,0);
    add_edge(3,4,1,0);
    add_edge(6,5,1,0);
    add_edge(5,7,1,0);
    add_edge(7,6,1,0);
    print();
    cout<<" Is Directed graph cyclic : "<<detect_cycle_directed()<<endl;
}