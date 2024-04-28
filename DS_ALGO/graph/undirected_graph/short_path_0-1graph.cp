#include <bits/stdc++.h>
#define v 5
using namespace std;

vector<pair<int,int> > graph[v]; // A 2D vector to represent graph as adjacency list; 1.end node, 2.weight
vector<bool> vis(v,0); // visited array
vector<int> dist(v,INT_MAX);

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

/* 
Problem Statement: Find the shortest path from src to all the other nodes of the given 
0-1 graph. Where weights can be either 0 or 1.

Algorithm: 
1. Do normal bfs with some modifications.Use deque where inseriton/deletion are allowed from both front and back.
Push src with 0 distance from the source. 
2. Till queue is not empty. Pop the front element. 
3. Visit all it's neighbours and if there is a shortert path then update it. 
4. if weight between front and it's neighbour is 0 then push in the front of the queue else push at the end. 

TC: O(E+V)

Why ? 
- Here every distance will only be updated once so tc is same as bfs. Same as in case of unweighted graph.
- Each node is updated level wise in case of bfs. So each node will be at shortest distance from the src at each level.
- We are pushing 0 in the front so first it will update all the possible nodes with shortest path first.
Then it will process edges with 1 weight. So visited array is not required because if any node is encountered 
twice then it will not update because it's already at the shortest path ( If any path through 0 exists then
it will be processed first). 

*/

void shortest_path(int src){
    deque<pair<int,int>> q;
    q.push_front({0,src});
    
    while(!q.empty()){
        int curr=q.front().second;
        int curr_w=q.front().first;
        q.pop_front();
        
        for(int i=0;i<graph[curr].size();i++){
            int en=graph[curr][i].first;
            int en_w=graph[curr][i].second;
            
            if(dist[en]>curr_w+en_w){
                dist[en]=curr_w+en_w;
                if(en_w==0)
                    q.push_front({dist[en],en});
                else
                    q.push_back({dist[en],en});
                
            }
                
        }
    }
}

int main() {
    
    add_edge(0,1,1,1);
    add_edge(0,2,1,1);
    add_edge(0,3,0,1);
    add_edge(1,4,1,1);
    add_edge(3,2,1,1);
    add_edge(3,4,0,1);
    print();
    
    shortest_path(0);
    
    for(int i=0;i<v;i++)
        cout<<i<<"("<<dist[i]<<") |";
    cout<<endl;
}


