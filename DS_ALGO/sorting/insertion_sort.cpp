#include <iostream>

using namespace std;
/*Algorithm
1. Take each element starting from index 1 and place it in it's right position towards left. 
2. iterate through j=i to 0 and swap if greater element is present. 
*/

void insertion_sort(int a[],int n){
    for(int i=1;i<n;i++){
        for(int j=i;j>=0;j--){
            if(a[j]<=a[j-1])
            swap(a[j],a[j-1]);
        }
    }
}

int main() {
    int a[16]={5,4,4,1,2,3,1,5,0,10,0,4,3,5,2,6};
    insertion_sort(a,16);
    
    for(int i=0;i<16;i++)
    cout<<a[i]<<" ";
    
}