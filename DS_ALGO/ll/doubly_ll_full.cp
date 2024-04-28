#include <iostream>
using namespace std;

// Doubly linked list all operations 

struct Node {
    public:
    int val;
    Node* next;
    Node* prev;
};

Node* getlastnode(Node* head){
    while(head!=NULL&&head->next!=NULL)
    head=head->next;
    return head;
}



void createll(Node** head){
    Node* temp,*temp2;
    
    for(int i=0;i<5;i++){
        temp=new Node();
        temp->val = rand()%10;
        temp->next=NULL;
        temp->prev=NULL;
        if(*head==NULL)
        *head=temp;
        else{
           temp2=getlastnode(*head);
           temp2->next=temp;
           temp->prev=temp2;
        }
    }
}

void insertb(Node** head,int val){
    Node* temp= new Node();
    temp->val=val;
    temp->next = *head;
    temp->prev=NULL;
    (*head)->prev=temp;
    *head = temp;
}

void inserte(Node** head,int val){
    Node* temp= new Node();
    temp->val=val;
    temp->next = NULL;
    temp->prev=getlastnode(*head);
    getlastnode(*head)->next=temp;
}



void searchll(Node *head,int val){
    int pos=1;
    cout<<"val "<<val<<": ";
    while(head!=NULL){
        if(head->val==val)
        cout<<pos<<" ";
        pos++;
        head=head->next;
    }
    cout<<endl;
}

void sortll(Node** head){
    bool flag= true;
    Node* curr=*head,*nextn;
    
    if(*head==NULL||*head!=NULL&& (*head)->next==NULL)
        return; 
    
    while(flag){
        curr = *head;
        nextn= (*head)->next;
        
        while(nextn!=NULL){
            if(curr->val > nextn->val){
                swap(curr->val,nextn->val);
                flag =false;
            }
            curr = nextn;
            nextn=nextn->next;
        }
        if(flag)
            return;
        else
            flag = true;
    }
}


void printll(Node* head){
    while(head!=NULL){
        cout<<head->val<<" ";
        head=head->next;
    }
    cout<<endl;
}

void print_rll(Node* head){
    while(head->next!=NULL){
        head=head->next;
    }
    while(head!=NULL){
        cout<<head->val<<" ";
        head=head->prev;
    }
    cout<<endl;
}

int main() {
    Node* head = NULL,*temp=NULL;

   
  createll(&head);
   
    printll(head);
    insertb(&head,11);
    printll(head);
    inserte(&head,13);
    printll(head);
    searchll(head,6);
    printll(head);
    sortll(&head); //bubble sort
    printll(head);
    print_rll(head);
}