#include <bits/stdc++.h>
using namespace std;

struct Node{
    int val;
    Node* left;
    Node* right;
};

Node* create_bin_tree(int &n){
    if(n==0) return NULL;
    
    Node * temp= new Node();
    temp->val=n--+rand()%100;
    
    temp->left=create_bin_tree(n);
    temp->right=create_bin_tree(n);
    return temp;
}


Node* insert(Node* root,int val){
    if(root==NULL){
        Node* temp= new Node();
        temp->val=val;
        temp->left=NULL;
        temp->right= NULL;
        return temp;
    }
    if(val<=root->val)
       root->left= insert(root->left,val);
    else
       root->right= insert(root->right,val);
    return root;
}

Node* create_bst(int n){
    Node* root=NULL;
    for(int i=0;i<n;i++)
        root = insert(root,rand()%10);
    
    return root;
}


int find_min(Node* root){
    if(root==NULL) return INT_MAX;
    int l_min= find_min(root->left);
    int r_min= find_min( root->right);
    return min(root->val,min(l_min,r_min));
}

int find_max(Node* root){
    if(root==NULL) return INT_MIN;
    int l_max= find_max(root->left);
    int r_max= find_max(root->right);
    return max(root->val,max(l_max,r_max));
}

Node* delete_node( Node* root,int val){
    if(root==NULL) return NULL;
    if(val<root->val)
        root->left = delete_node(root->left,val);
    else if(val>root->val)
        root->right = delete_node(root->right,val);
    else{
        int temp;
        if(root->left==NULL&&root->right==NULL)
            return NULL;
        if(root->left==NULL){
            temp=find_min(root->right);
            root->val= temp;
            root->right=delete_node(root->right,temp);
        }else{
            temp=find_max(root->left);
            root->val= temp;
            root->left=delete_node(root->left,temp);
        }
    }
    return root;
}


void preorder(Node* root){
    if(root==NULL) return; 
    cout<<root->val<<" ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(Node* root){
    if(root==NULL) return; 
    inorder(root->left);
    cout<<root->val<<" ";
    inorder(root->right);
}

void postorder(Node* root){
    if(root==NULL) return; 
    postorder(root->left);
    postorder(root->right);
    cout<<root->val<<" ";
}

void level_order(Node* root){
    queue<Node*> q;
    if(root==NULL) return;
    Node* left,*right;
    q.push(root);
    
    while(!q.empty()){
        cout<<q.front()->val<<" ";
        left=q.front()->left;
        right=q.front()->right;
        if(left!=NULL) q.push(left);
        if(right!=NULL) q.push(right);
        q.pop();
    }
    cout<<endl;
}

int find_height(Node* root){
    if(root==NULL) return -1;
    if(root->left==NULL&&root->right==NULL) return 0;
    return max(find_height(root->left),find_height(root->right))+1;
}

bool check_bst(Node* root, int min_, int max_){
    if(root==NULL) return true;
    
    if((root->val>= min_&&root->val<=max_)&&
        check_bst(root->left,min_,root->val)&&check_bst(root->right,root->val,max_))
        return true;
    else
        return false;
     
    
}

Node* find(Node*root,int val){
    if(root==NULL)
        return NULL;
    
    while(root!=NULL){
        if(root->val>val)
            root=root->left;
        else if(root->val<val)
            root=root->right;
        else
        return root;
    }
    return root;
}


/*
Case1 : When target node has right child then it's successor will be 
          in right subtree so find min in right subtree.
          
Case 2: When target node doesn't have right child then go to the nearest ancestor for
        which the given node is in it's left subtree. 
*/
int inorder_successor(Node* root,int val){
    Node* curr= find(root,val),*temp=NULL,*ancestor=NULL;
    
    if(curr==NULL) return -1;
    if(curr->right!=NULL) //case 1 
        return find_min(curr->right);
    else{ //case 2
        temp=root;
        while(temp!=curr){
            if(temp->val>=curr->val){
                ancestor=temp;
                temp=temp->left;
            } else
                temp=temp->right;
        }
        if(ancestor==NULL)
          return -1;
        else
            return ancestor->val;
    }
}

void print_tree(Node* root){
    if(root==NULL){
        return;
    }
    cout<<root->val<<" ";
    if(root->left==NULL){
        cout<<"ln"<<" ";
    }
    if(root->right==NULL){
        cout<<"rn"<<" ";
    }
    print_tree(root->left);
    print_tree(root->right);
}

int main() {
  srand(time(NULL));
  Node* rootbt=NULL, *temp=NULL,*rootbst=NULL;
  int n=5,min_=INT_MIN,max_=INT_MAX;
  // Binary Tree.
  cout<<"Binary Tree"<<endl;
  rootbt = create_bin_tree(n);
  
  print_tree(rootbt),cout<<endl;
  preorder(rootbt),cout<<endl;
  inorder(rootbt),cout<<endl;
  postorder(rootbt),cout<<endl;
  level_order(rootbt);
  
  cout<<find_min(rootbt)<<" "<<find_max(rootbt)<<" "<<endl;
  cout<<find_height(rootbt)<<" "<<check_bst(rootbt,min_,max_)<<endl<<endl;
  
  
  
  //Binary Search Tree.
  cout<<"Binary search Tree"<<endl;
  n=10,min_=INT_MIN,max_=INT_MAX;
  rootbst = create_bst(n);
  
  print_tree(rootbst),cout<<endl;
  preorder(rootbst),cout<<endl;
  inorder(rootbst),cout<<endl;  // for bst inorder will give sorted data.
  postorder(rootbst),cout<<endl;
  level_order(rootbst);
  
  cout<<find_min(rootbst)<<" "<<find_max(rootbst)<<" "<<endl;
  cout<<find_height(rootbst)<<" "<<check_bst(rootbst,min_,max_)<<endl;
  
  //Node deletetion
//   inorder(rootbst),cout<<endl;
//   rootbst= delete_node(rootbst,2);
//   inorder(rootbst),cout<<endl;
//   rootbst= delete_node(rootbst,3);
//   inorder(rootbst),cout<<endl;
//   rootbst= delete_node(rootbst,3);
//   inorder(rootbst),cout<<endl;
//   rootbst= delete_node(rootbst,3);
//   inorder(rootbst),cout<<endl;
//   rootbst= delete_node(rootbst,9);
//   inorder(rootbst),cout<<endl;
//   print_tree(rootbst),cout<<endl;
  
  cout<<find_height(rootbst)<<" "<<check_bst(rootbst,min_,max_)<<endl;
  cout<<endl;
  //Inorder Successor in bst
  cout<<inorder_successor(rootbst,1)<<endl;
  cout<<inorder_successor(rootbst,2)<<endl;
  cout<<inorder_successor(rootbst,3)<<endl;
  cout<<inorder_successor(rootbst,4)<<endl;
  cout<<inorder_successor(rootbst,5)<<endl;
  cout<<inorder_successor(rootbst,6)<<endl;
  cout<<inorder_successor(rootbst,7)<<endl;
  cout<<inorder_successor(rootbst,8)<<endl;
  cout<<inorder_successor(rootbst,9)<<endl;
  cout<<inorder_successor(rootbst,0)<<endl;
  
}
