#include <bits/stdc++.h>
#define SIZE 26
using namespace std;

struct Trie{
    Trie* child[SIZE];
    bool isend;
};

Trie* getNewNode(){
    Trie* temp= new Trie();
    temp->isend=false;
    for(int i=0;i<SIZE;i++)
    temp->child[i]=NULL;
    return temp;
}

void insert(Trie* root,string key){
    int idx;
    for(int i=0;i<key.length();i++){
        idx=key[i]-'a';
        if(root->child[idx]==NULL)
            root->child[idx]=getNewNode();
        root=root->child[idx];
    }
    root->isend=true;
}

bool search(Trie* root,string word){
    int idx;
    for(int i=0;i<word.length();i++){
        idx=word[i]-'a';
        if(root->child[idx]==NULL) 
            return false;
        root=root->child[idx];
    }
    return (root->isend);
}

bool isleafnode(Trie* root){
    for(int i=0;i<SIZE;i++){
        if(root->child[i]!=NULL)
        return false;
    }
    return true;
}

/*
Algo : 
1. Key may not be there in trie. Delete operation should not modify trie.
2. Key present as unique key (no part of key contains another key (prefix),
nor the key itself is prefix of another key in trie). Delete all the nodes.
3. Key is prefix key of another long key in trie. Unmark the leaf node.
4. Key present in trie, having atleast one other key as prefix key. 
Delete nodes from end of key until first leaf node of longest prefix key.
*/

bool delete_key(Trie* root,string key){
    
    if(root==NULL) return false; 
    if(!key.empty()){
       if(!search(root,key)) return false; 
    }
    
    
    if(root->isend){
        if(key.empty()){
            if(isleafnode(root))
                return true;
            else{
                root->isend=false;
                return false;
            }
        }
    }
    
    
    int idx=key[0]-'a';
    key.erase(key.begin());
    if(delete_key(root->child[idx],key)){
        root->child[idx]=NULL;
        if(!root->isend&&isleafnode(root))
            return true;
    }
    return false;
    
}

void printtrie(Trie* root,string ans){
    if(root->isend){
        cout<<ans<<endl;
    }
    for(int i=0;i<SIZE;i++){
        if(root->child[i]==NULL)
            continue;
        ans+=(char)('a'+i);
        
        printtrie(root->child[i],ans);
        ans.pop_back();   
    }
}

int main() {
   string keys[] = {"dee","rahul","deepak","deepmk","devab","devac"};
    Trie *root=getNewNode();
    
    //form trie
    for(int i=0;i<6;i++)
        insert(root,keys[i]);
    
    printtrie(root,"");
    ///search word in trie
    cout<<endl<<"search word"<<endl<<endl;;
    
    for(int i=1;i>=0;i--)
        cout<<keys[i]<<" "<<search(root,keys[i])<<endl;
    
    cout<<search(root,"a")<<endl;
    cout<<search(root,"deepak")<<endl;
    
    cout<<endl;
    
    //delete word in trie
    
    for(int i=0;i<6;i++){
        delete_key(root,keys[i]);
        cout<<endl;
        printtrie(root,"");
    }
        
    printtrie(root,"");
}