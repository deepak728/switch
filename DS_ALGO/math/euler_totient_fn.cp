#include <bits/stdc++.h>
using namespace std;

void find_all(vector<int> & ans,int n){
    for(int i=0;i<ans.size();i++)
    ans[i]=i;
    
    for(int i=2;i<=n;i++){ // we have to go till n because we have to multiply (1-1/p) for all it's multiple.
        if(ans[i]==i){
            for(int j=i;j<=n;j+=i){
                ans[j]=ans[j]-ans[j]/i; // multiplying (1-1/p) to all multiple of i
            }
        }
    }
    return;
}


int find(int n){
    int ans=n;
    
    for(int i=2;i*i<=n;i++){
        if(n%i==0){
            while(n%i==0)
            n/=i;
            ans=ans-ans/i;  // equal to phi(n) = n*(1-1/p1)(1-1/p2)..(1-1/pk)
        }
    }
    if(n>1) // if any factor is greater than root(n); only one is possible
    ans=ans-ans/n;
    return ans;
    
}

int main() {
    //Euler totient function to find no of co primes of n from [1,n]
    /* formula : phi(n)= n*(1-1/p1)(1-1/p2)....(1-1/pk)
    */
    vector<int> ans(17);
    find_all(ans,16);
    
    for(int i=1;i<ans.size();i++)
    cout<<ans[i]<<" ";
    cout<<endl;
    for(int i=1;i<17;i++)
    cout<<find(i)<<" ";
    cout<<endl;
}