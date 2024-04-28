#include <iostream>
using namespace std;

int find(int st,int en, int a[]){
    int pivot=st;
    
    int i=st;
    int temp;
    while(i<en){
        if(a[i]<=a[en]){
        temp=a[i];
        a[i]=a[pivot];
        a[pivot]=temp;
        pivot++;
       }
    i++;
    }
    temp=a[en];
    a[en]=a[pivot];
    a[pivot]=temp;
    return pivot;
}

void sort(int st,int en, int a[], int n){
    
    if(st>=en)
    return;
    int pivot=find(st,en,a);
    sort(0,pivot-1,a,n);
    sort(pivot+1,en,a,n);
    
    return ;
}

int main() {
    int a[6]={0,1,6,2,1,5};
    int n= sizeof(a)/sizeof(a[0]);
    sort(0,n-1,a,6);
    for(int i=0;i<n;i++)
    cout<<a[i]<<" ";
}
