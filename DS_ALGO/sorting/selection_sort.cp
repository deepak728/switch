#include <bits/stdc++.h>

using namespace std;
/*Algorithm
1. left side is sorted array and all elements after left is unsorted. Initially left =0;
2. Find smallest in right unsorted side and swap with left index and increase left. 
3. array from (last to n is unsorted).
*/

void selection_sort(int a[],int n){
    int left=0;
    int min_right;
    int min_index;
    while(left<n){
        min_right=a[left];
        for(int i=left;i<n;i++){
            if(a[i]<=min_right){
                min_right=a[i];
                min_index=i;
            }
        }
        swap(a[left],a[min_index]);
        left++;
    }
}

int main() {
    int a[16]={5,4,4,1,2,3,1,5,0,10,0,4,3,5,2,6};
    selection_sort(a,16);
    
    for(int i=0;i<16;i++)
    cout<<a[i]<<" ";
}