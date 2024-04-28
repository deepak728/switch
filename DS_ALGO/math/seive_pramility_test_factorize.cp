#include <bits/stdc++.h>
using namespace std;
vector<bool> isprime(101,1); // for the first 100 numbers;

void seive(long long int n){
    isprime[0]=isprime[1]=0;
    
    for(long long int i=2;i*i<=n;i++){
        if(isprime[i]){
            for(long long int j=i*i;j<=n;j+=i){
                isprime[j]=false;
            }
        }
    }
}

bool primalitytest(long long int x){ // to check if a no is prime or not
    for(long long int i=2;i*i<=x;i++){
        if(x%i==0)
        return false;
    }
    return true;
}

bool primalitytest_optimized(long long int x){
    if(x%2==0)
    return false;
    
    for(long long int i=3;i*i<x;i+=2){ // only check for odd numbers 
        if(x%i==0)
        return false;
    }
    return true;
}

void prime_factors(vector<int> &ans,int x){
    for(int i=2;i*i<=x;i++){
        while(x%i==0){
            ans.push_back(i);
            x/=i;
        }
    }
     if(x>1)
    ans.push_back(x); 
    
/* for that factor which is >= root(x).
Only one factor can be > root(x) and max 2 factors can be equal to x in case of 
perfect square.
It can also be optimized by removing all the 2 from the no earlier. 
then only check for odd numbers. 
*/
   
}

int main() {
    seive(100);
    vector<int> ans;
    cout<<isprime[95]<<isprime[97]<<endl;
    cout<<primalitytest(1024)<<primalitytest(131)<<endl;
    cout<<primalitytest_optimized(1024)<<primalitytest_optimized(125)<<endl;
    
    prime_factors(ans,198);
    
    for(int i=0;i<ans.size();i++)
    cout<<ans[i]<<" ";
    
    
    
}