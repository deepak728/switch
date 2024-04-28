#include <bits/stdc++.h>
using namespace std;

int fibo_rec(int n){ // TC: O(2^n) can be optimized by storing known values 
    if(n<2)
    return n;
    return fibo_rec(n-1)+fibo_rec(n-2);
} 

void find_fibo(vector<int>& ans,int n){ // TC O(n)
    ans.push_back(0);
    if(n==0) return;
    ans.push_back(1);
    
    int a=ans[0], b = ans[1];
    while(n>1){
        ans.push_back(a+b);
        a=b;
        b=ans.back();
        n--;
    }
    return; 
}

pair<int,int> fibo(int n){ // it takes log(n) time. // details in copy 
    if(n==0)
    return {0,1};
    
    pair<int,int> temp;
    temp=fibo(n/2);
    
    int a = temp.first*(2*temp.second- temp.first);
    int b = temp.second*temp.second+temp.first*temp.first;
    
    if(n%2==0) // when n is even a is Fn
    return {a,b}; 
    else  // when n is odd b is Fn
    return {b,a+b};
}


int main() {
    vector<int> ans;
    find_fibo(ans,9);
    
    for(int i=0;i<ans.size();i++)
    cout<<ans[i]<<" ";
    cout<<endl;
    for(int i=0;i<10;i++)
    cout<<fibo(i).first<<" ";
    cout<<endl;
    for(int i=0;i<10;i++)
    cout<<fibo_rec(i)<<" ";
    cout<<endl;
}