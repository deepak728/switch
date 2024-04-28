#include <bits/stdc++.h>
#define v 9
using namespace std;

vector<pair<int,int> > graph[v]; // A 2D vector to represent graph as adjacency list; 1.end node, 2.weight
vector<bool> vis(v,0); // visited array
vector<int> dist(v,INT_MAX);
vector<vector<int>> distij(v,vector<int>(v,1000));

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


/* Algo 
1. Create a 2d array and initialize all the value with inf.
2. maark all diagonal element 0 ;
3. mark all the given edge with it's weight. 
4. Then run 3 loops (k,i,j) for all nodes. 
5. k : means what will if the shortest distance between i and j if k is the intermediate node.
dist[i][j] = dist[i][k] + dist[k][j] when k is the intermediate node. 
*/

void floyd_warshall(){
    
    //set diagonal element to zero 
    for(int i=0;i<v;i++){
        distij[i][i]=0;
    }
    
    //mark weights of each edge
    for(int i=0;i<v;i++){
        for(int j=0;j<graph[i].size();j++){
            distij[i][graph[i][j].first]=graph[i][j].second;
        }
    }
    
    for(int k=0;k<v;k++){
        for(int i=0;i<v;i++){
            for(int j=0;j<v;j++)
                if(distij[i][k]!=1000&&distij[k][j]!=1000) // incase of negative weights. It should not update the edge (i,j) if there is no path between 
                                                           //(i,k) and (k,j).
                    distij[i][j]=min(distij[i][j],distij[i][k]+distij[k][j]);
        }
    }
    
    //print distances
    cout<<endl;
    cout<<"Shortest distance from all pairs of node "<<endl;
    for(int i=0;i<v;i++){
        for(int j=0;j<v;j++)
            cout<<distij[i][j]<<" ";
            cout<<endl;
    }
}


/*
1. If any weight is updated at nth iteration then negative cycle is present. 
*/


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
    
    // cout<<"Shortest path from source to all other nodes"<<endl;
    
    
    // for(int i=0;i<v;i++){
    //     cout<<"("<<i<<")"<<dist[i]<<"  ";
    // }
    // cout<<endl;
    
    // Print all the edge in the shorted path. Multiple such paths are possible. 
    
    
    /* Solution of 
    *Floyd warshall can be used to find to find the shortest distance between all the two pairs of node. 
    *It can be used in both directed (positive and negative), undirected (positive)
    *Convert undirected to directed graph. (If negative then it will form and negative cycle)
    *Will not work for negative edge cycle. 
    
    1. Find the shortest path between source to all other nodes.
    */
    
    // add_edge(0,1,1,1);
    // add_edge(0,2,2,1);
    // add_edge(0,4,3,1);
    // add_edge(1,2,1,1);
    // add_edge(2,3,1,1);
    // add_edge(2,4,1,1);
    // add_edge(3,4,1,1);
    //print();
    floyd_warshall();
    
}


