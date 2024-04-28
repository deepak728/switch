#include <bits/stdc++.h>
using namespace std;

struct Node{
    int vtx;
    int weight;
    Node* next;
};

struct Edge{
    int vtx;
    int weight;
};

class Graph{
    public:
        int v;
        vector<vector<int> > adj_mat;    // adjacency matrix
        vector<vector<Edge*> > adj_list;   // adjacency list using vector
        vector<Node*> adj_llist;       // adjacency list using linked list
        vector<bool> visited;
        Node* ntemp=NULL,*head;
        Edge* etemp=NULL;
        
        Graph(int n){ //initialize graph
            adj_mat.resize(n,vector<int>(n+1,INT_MAX));
            adj_list.resize(n+1);
            adj_llist.resize(n+1,ntemp);
            visited.resize(n,0);
            v=n;
        }
        
        void add_edge(int st,int en,int w,bool bi){
            adj_mat[st][en]=w;   // add edge in adjacency matrix
            
            //add edge to adjacency list
            etemp=new Edge();
            etemp->vtx=en;
            etemp->weight=w;
            adj_list[st].push_back(etemp);
            
            //add edge to adjacency linked list
            ntemp=new Node();
            ntemp->vtx=en;
            ntemp->weight=w;
            ntemp->next==NULL;
            head=adj_llist[st];
            if(head==NULL)
                adj_llist[st]=ntemp;
            else{
                while(head->next!=NULL) head =head->next;
                head->next=ntemp;
            }
            
            if(bi) // make it bidirectional
                add_edge(en,st,w,false);
        }
        
        void bfs(){
            cout<<"BFS using adjacency matrix"<<endl;
            queue<int> q;
            for(int i=0;i<v;i++){
                if(!visited[i]){
                    visited[i]=true;
                    q.push(i);
                    while(!q.empty()){
                        int par=q.front();
                        q.pop();
                        cout<<par<<" ";
                        for(int j=0;j<v;j++){
                            if(adj_mat[par][j]!=INT_MAX&&!visited[j])
                                visited[j]=true,q.push(j);
                        }
                    }
                }
            }
            cout<<endl;
            
            cout<<"BFS using adjacency list "<<endl;
            visited.resize(0);
            visited.resize(v,false);
            for(int i=0;i<v;i++){
                if(!visited[i]){
                    visited[i]=true;
                    q.push(i);
                    while(!q.empty()){
                        int par=q.front();
                        q.pop();
                        cout<<par<<" ";
                        for(int j=0;j<adj_list[par].size();j++){
                            if(!visited[adj_list[par][j]->vtx]){
                               visited[adj_list[par][j]->vtx]=true;
                               q.push(adj_list[par][j]->vtx); 
                            }     
                        }
                    }
                }
            }
            cout<<endl;
            
            cout<<"BFS using adjacency linked list "<<endl;
            visited.resize(0);
            visited.resize(v,false);
            for(int i=0;i<v;i++){
                if(!visited[i]){
                    visited[i]=true;
                    q.push(i);
                    while(!q.empty()){
                        int par=q.front();
                        q.pop();
                        cout<<par<<" ";
                        head=adj_llist[par];
                        while(head!=NULL){
                            if(!visited[head->vtx]){
                                visited[head->vtx]=true;
                                q.push(head->vtx);
                            }
                            head=head->next;
                        }
                    }
                }
            }
            cout<<endl<<endl;
        }
        
        void dfs_iterative(){
            cout<<"Iterative DFS using adjacency list"<<endl;
            visited.resize(0);
            visited.resize(v,false);
            stack<int> s;
            for(int i=0;i<v;i++){
                if(!visited[i]){
                    visited[i]=true;
                    s.push(i);
                    while(!s.empty()){
                        int par=s.top();
                        s.pop();
                        cout<<par<<" ";
                        for(int j=0;j<adj_list[par].size();j++){
                            if(!visited[adj_list[par][j]->vtx]){
                                visited[adj_list[par][j]->vtx]=true;
                                s.push(adj_list[par][j]->vtx);
                            }
                        }
                    }
                }
            }
            cout<<endl<<endl;
        }
        
        void dfs_rec(int ver){
            visited[ver]=true;
            cout<<ver<<" ";
            for(int i=0;i<adj_list[ver].size();i++){
                if(!visited[adj_list[ver][i]->vtx])
                    dfs_rec(adj_list[ver][i]->vtx);
            }
        }
        
        void dfs(){
            cout<<"Recursive DFS using adjacency list"<<endl;
            visited.resize(0);
            visited.resize(v,false);
            
            for(int i=0;i<v;i++){
                if(!visited[i])
                    dfs_rec(i);
            }
            cout<<endl;
        }
        
        
};

int main() {
    Graph g(6);
    g.add_edge(0,4,8,1);
    g.add_edge(0,1,10,1);
    g.add_edge(1,2,11,1);
    g.add_edge(2,3,9,1);
    g.bfs();
    g.dfs_iterative();
    g.dfs();
  
}


