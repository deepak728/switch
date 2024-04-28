#include <iostream>

using namespace std;

void merge(int a[],int n,int r, int l,int mid){
    if(l==r)
    return;
    
    int left[mid-l+1];
    int right[r-mid];
    
    for(int i=0;i<mid-l+1;i++)
        left[i]=a[l+i];
    for(int i=0;i<r-mid;i++)
        right[i]=a[mid+1+i];
        
    int i=l,j=0,k=0;
    
    while(i<=r&&j<(mid-l+1)&&k<(r-mid)){
        if(left[j]<=right[k])
        a[i++]=left[j++];
        else
        a[i++]=right[k++];
    }
    while(i<=r&&j<(mid-l+1))
    a[i++]=left[j++];
    while(i<=r&&k<(r-mid))
    a[i++]=right[k++];
    
}

void iterative_merge(int a[],int n){
    
    for(int sub_size=1;sub_size<=n;sub_size=sub_size*2){
        for(int left=0;left<n;left+=2*sub_size){
            int right =min(n-1,left+2*sub_size-1);
            int mid = (right+left)/2;
            
            merge(a,n,right,left,mid);
        }
       
    }
}

int main() {
    int a[16]={5,4,4,1,2,3,1,5,0,10,0,4,3,5,2,6};
    iterative_merge(a,16);
    
    for(int i=0;i<16;i++)
    cout<<a[i]<<" ";
}