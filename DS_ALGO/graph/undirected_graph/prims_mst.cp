#include <bits/stdc++.h>
#define v 9
using namespace std;
typedef pair<int, pair<int,int> > pii;   // weight,ver, parent

vector<pair<int,int> > graph[v]; // A 2D vector to represent graph as adjacency list; 1.end node, 2.weight
vector<bool> vis(v,0); // visited array
vector<int> parent(v,-1);
vector<pair<int,int>> mst[v];

void add_edge(int st,int en,int w, bool bi){
    graph[st].push_back(make_pair(en,w));
    if(bi) add_edge(en,st,w,false);
}

void form_mst(int st,int en,int w, bool bi){
    mst[st].push_back(make_pair(en,w));
    if(bi) form_mst(en,st,w,false);
}

void print_mst(){
    cout<<"MST Graph View"<<endl;
    for(int i=0;i<v;i++){
        cout<<i<<" -> ";
        for(int j=0;j<mst[i].size();j++)
            cout<<mst[i][j].first<<"("<<mst[i][j].second<<") -> ";
        cout<<endl;
    }
    cout<<endl;
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

// minimum spanning tree is the subset of undirected connected graph. 
int prims_mst(){
    priority_queue<pii,vector<pii>, greater<pii>> q; // syntax of min heap
    int mst_cost=0;
    q.push(make_pair(0,make_pair(0,-1)));  // starting node is 0

    while(!q.empty()){
        pii curr=q.top();
        q.pop();
        int curr_v=curr.second.first;
        if(vis[curr_v]) continue;
        
        mst_cost+=curr.first;  // add weight of popped element which is minimum among all the vis nodes adj nodes.
        vis[curr_v]=true;    // nope can't mark visited before pushing it to queue.
                              // Because when it is popped then only it bcomes the part of mst
        parent[curr_v]=curr.second.second;
        
        for(int i=0;i<graph[curr_v].size();i++){
            if(!vis[graph[curr_v][i].first]){
                q.push(make_pair(graph[curr_v][i].second, make_pair(graph[curr_v][i].first, curr_v)));
            }
        }
    }
    return mst_cost;
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
    cout<<"MST Cost: "<<prims_mst()<<endl<<endl;
    
    for(int i=1;i<v;i++){  // it will only give us one min spanning tree there can be multiple. In that case use map.
        form_mst(i,parent[i],0,1);   
    }
    print_mst();
    
}


