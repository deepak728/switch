#include <iostream>
using namespace std;

void merge(int a[],int left[], int right[],int l,int r,int n){
    
    
    int i=0,j=0,k=0;
    
    while(i<n&&j<l&&k<r){
        if(left[j]<=right[k])
        a[i++]=left[j++];
        else 
        a[i++]=right[k++];
    }
    while(j<l){
        a[i++]=left[j++];
    }
    
    while(k<r){
        a[i++]=right[k++];
    }
    
}


void sort(int a[],int n){
    if(n<2)
    return; 
    int mid = n/2;
    int left[mid];
    int right[n-mid];
    for(int i=0;i<mid;i++)
       left[i]=a[i];
    for(int i=0;i<n-mid;i++)
    right[i]=a[mid+i];
    
    sort(left,mid);
     sort(right,n-mid);
    
    merge(a,left,right,mid,n-mid,n);
    
}


int main() {
    int a[6]={0,1,6,2,1,5};
    int n= sizeof(a)/sizeof(a[0]);
    sort(a,n);
    cout<<endl;
    for(int i=0;i<n;i++)
    cout<<a[i]<<" ";
}
