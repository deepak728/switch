#include <bits/stdc++.h>

using namespace std;
/*Algorithm
swap each pair n times
*/

void bubble_sort(int a[],int n){
    int flag=0; 
    for(int i=0;i<n;i++){
        flag=0;
        for(int j=1;j<n;j++){
            if(a[j]<=a[j-1]){
            swap(a[j],a[j-1]);
            flag=1;
            }
        }
        if(!flag)
        break;
    }
}

int main() {
    int a[16]={5,4,4,1,2,3,1,5,0,10,0,4,3,5,2,6};
    bubble_sort(a,16);
    int b;
    for(int i=0;i<16;i++)
    cout<<a[i]<<" ";
}