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
        Node* ntemp=NULL,*head;
        Edge* etemp=NULL;
        
        Graph(int n){ //initialize graph
            adj_mat.resize(n,vector<int>(n+1,INT_MAX));
            adj_list.resize(n+1);
            adj_llist.resize(n+1,ntemp);
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
        
        void print(){
            cout<<"Printing uisng adjacency matrix"<<endl;
            for(int i=0;i<v;i++){
                cout<<i<<" -> ";
                for(int j=0;j<v;j++){
                    if(adj_mat[i][j]!=INT_MAX)
                        cout<<j<<"("<<adj_mat[i][j]<<") -> ";
                }
                cout<<endl;
            }
            cout<<endl;
            
            cout<<"Printing using adjacency list "<<endl;
            for(int i=0;i<v;i++){
                cout<<i<<" -> ";
                for(int j=0;j<adj_list[i].size();j++)
                    cout<<adj_list[i][j]->vtx<<"("<<adj_list[i][j]->weight<<") ->";
                cout<<endl;
            }
            cout<<endl;
            
            cout<<"Printing using adjacency linked list "<<endl;
            for(int i=0;i<v;i++){
                cout<<i<<" -> ";
                head=adj_llist[i];
                while(head!=NULL){
                    cout<<head->vtx<<"("<<head->weight<<") -> ";
                    head=head->next;
                }
                cout<<endl;
            }
        }
        
};

int main() {
    Graph g(6);
    g.add_edge(0,4,8,1);
    g.add_edge(0,1,10,1);
    g.add_edge(1,2,11,1);
    g.add_edge(2,3,9,1);
    g.print();
  
}


