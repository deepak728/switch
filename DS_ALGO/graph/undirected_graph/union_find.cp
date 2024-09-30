#include <bits/stdc++.h>
using namespace std;

int findRoot(int a,vector<int> &par){
  while(par[a]!=a){
    a=par[a];
  }
  return a;
}

void Union(int a,int b,vector<int> &arr, vector<int> &par){
  int rootA = findRoot(a,par);
  int rootB = findRoot(b,par);
  
  par[rootA] = rootB;
  
}

bool find(int a ,int b, vector<int> &par){
  if(findRoot(a,par) == findRoot(b,par)) return true;
  return false;
}

int main() 
{
    vector<int> arr ={0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int n=arr.size();
    vector<int> par(n);
    for(int i=0;i<n;i++){
      par[i]=i;
    }
    
    Union(2, 1,arr,par);
    Union(4, 3,arr,par);
    Union(8, 4,arr,par);
    Union(9, 3,arr,par);
    Union(6, 5,arr,par);
    
    for(int i=0;i<n;i++){
      cout<<arr[i]<<" "<<par[i]<<endl;
    }
    cout<<endl<<endl;
    
    cout<<find(4,2,par)<<endl;
    cout<<find(3,3,par)<<endl;
    cout<<find(4,9,par)<<endl;
    cout<<find(5,7,par)<<endl;
    
    
}
