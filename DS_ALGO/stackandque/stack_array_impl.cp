#include <iostream>
#define max 3
using namespace std;

int stack[max][max];
int top=-1;
int row=0;

bool empty(){
    return top==-1 ? true : false;
}

void push(int val){
    top++;
    if(top%max==0){
        row=top/max;
        if(row>=max){
            top--;
            row--;
            cout<<"Stack overflow "<<endl;
            return;
        }
    }
    stack[row][top%max]=val;
}

void pop(){
    if(empty()){
        cout<<"Stack is empty"<<endl;
        return;
    }
    
    if(top%max==0){
        top--;
        row=top/max;
    }else 
    top--;
}

int top_ele(){
    if(empty()){
        cout<<"Stack is empty "<<endl;
        return -1;
    }
    return stack[row][top%max];
}

void print(){
    for(int i=0;i<=row;i++){
        for(int j=0;j<max;j++)
        cout<<stack[i][j]<<" ";
        cout<<endl;
    }
    cout<<endl;
}

int main() {
    pop();
    print();
    push(7);
    push(5);
    
    push(3);
    print();
    cout<<top_ele()<<endl;
    push(6);
    print();
    pop();
    print();
    cout<<top_ele()<<endl;
    push(7);
    //print();
    cout<<top_ele()<<endl;
    push(1);
    push(2);
    push(3);
    push(4);
    push(8);
    print();
    cout<<" "<<top<<" "<<endl;
    push(9);
    cout<<" "<<top<<" "<<endl;
    print();
    pop();
    pop();
    cout<<top_ele()<<endl;
    print();
}