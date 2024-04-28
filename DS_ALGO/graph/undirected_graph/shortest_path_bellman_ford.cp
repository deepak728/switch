#include <bits/stdc++.h>
#define v 10
using namespace std;

vector<pair<int,int> > graph[v]; // A 2D vector to represent graph as adjacency list; 1.end node, 2.weight
vector<bool> vis(v,0); // visited array
vector<int> dist(v,INT_MAX);
vector<pair<int,int>> spgraph[v];

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

void printsp(){
    cout<<"Graph View"<<endl;
    for(int i=0;i<v;i++){
        cout<<i<<" -> ";
        for(int j=0;j<spgraph[i].size();j++)
            cout<<spgraph[i][j].first<<"("<<spgraph[i][j].second<<") -> ";
        cout<<endl;
    }
    cout<<endl;
}

/* Algo 
1. The outer loop traverses from  : .
2. Loop over all edges, check if the next node distance > current node distance + edge weight,
   in this case update the next node distance to "current node distance + edge weight"
*/

void bellman_ford(int src){
    dist[src]=0;
    
    for(int i=0;i<=v-1;i++){
        for(int j=0;j<v;j++){
            for(int k=0;k<graph[j].size();k++){
                int en=graph[j][k].first;
                int en_w= graph[j][k].second;
                dist[en]=min(dist[en],dist[j]+en_w);
            }
        }
    }
}

/*
1. If any weight is updated at nth iteration then negative cycle is present. 
*/
bool detect_negative_cycle(int src){
    bool isnegcycle=0;
    for(int i=0;i<v;i++){
        for(int j=0;j<graph[i].size();j++){
            int en=graph[i][j].first;
            int en_w= graph[i][j].second;
            if(dist[en]>dist[i]+en_w)
                return true;
        }
    }
    return false;
}

void dfs(int src,vector<int> temp){
         temp.push_back(src);
    if(src==4){
        for(auto i: temp)
        cout<<i<<" ";
        cout<<endl;
    }
    for(int i=0;i<spgraph[src].size();i++){
        dfs(spgraph[src][i].first,temp);
    }
}


/* Find all the edges in the shortest path ( there can be multiple shortest path) and print all paths. 
Algo : 
1. Find the shortest path to all other nodes from the source using dijkstra. 
2. Start from the destination node. 
3. if shortest path of adj nodes + weight == desti weight then push it to queue. Means that is a shortest path. 
4. Maintain a map for visited edges and for final answer.
5. Either check if that edge is already visited or checkif that node is visited by vis array. 
6. if not then push that edge.
7. Create a new adjacency list which will only contains the shortest path edges. 
8. form an undirected edge from child to parent. ( curr is parent and en is child. because we started from desti)
9. Apply dfs from source to print all the paths. 
*/


void paths(int src,int dest,int len){ 
    map<pair<int,int>,int> m;
    queue<int> q;
    q.push(dest);
    
    while(!q.empty()){
        int curr=q.front();
        q.pop();
        for(int i=0;i<graph[curr].size();i++){
            int en=graph[curr][i].first;
            int en_w=graph[curr][i].second;
            
            if(dist[curr]==dist[en]+en_w){
                if(m.find({curr,en})==m.end()){
                    m[{curr,en}]=en_w;
                    m[{en,curr}]=en_w;
                    q.push(en);
                    
                    spgraph[en].push_back({curr,en_w});// make a unidirectional graph from source to dest. 
                }
            }
        }
    }
    
    cout<<"All edges in shortest path from src to desti"<<endl;
    for(auto i:m){
        cout<<i.first.first<<" "<<i.first.second<<" "<<i.second<<endl;
    }
    cout<<endl;
    cout<<"Shortest path graph"<<endl;
    printsp();
    cout<<endl;
    cout<<"All Shortest path"<<endl;
    dfs(0,vector<int>{});
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
    // print();
    
    // cout<<"Shortest path from source to all other nodes"<<endl;
    
    
    // for(int i=0;i<v;i++){
    //     cout<<"("<<i<<")"<<dist[i]<<"  ";
    // }
    // cout<<endl;
    
    // Print all the edge in the shorted path. Multiple such paths are possible. 
    
    
    /* Solution of 
    *Bellman ford can be used to find to find the shortest distance between soucre and all the other nodes. 
    *It can be used in both directed (positive and negative), undirected ( positive)
    *Convert undirected to directed graph. (If negative then it will form and negative cycle)
    *Will not work for negative edge cycle. 
    
    1. Find the shortest path between source to all other nodes.
    2. Find the edges included in the shortest path from source to dest. 
    3. Print all the shortest path from source to desti. 
    */
    
    // add_edge(0,1,1,1);
    // add_edge(0,2,2,1);
    // add_edge(0,4,3,1);
    // add_edge(1,2,1,1);
    // add_edge(2,3,1,1);
    // add_edge(2,4,1,1);
    // add_edge(3,4,1,1);
    print();
    bellman_ford(0);
    cout<<endl;
    cout<<"Is negative cycle present :"<<detect_negative_cycle(0)<<endl<<endl;
    
    cout<<"Shortest distance from src to all other nodes "<<endl;
    for(int i=0;i<v;i++){
        cout<<"("<<i<<")"<<dist[i]<<"  ";
    }
    cout<<endl<<endl;
    
    paths(0,4,dist[3]); // Print All edges in shortest path from source to desti.
    
}


