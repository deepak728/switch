#include <iostream>
using namespace std;

// Singly linked list all operations 

struct Node {
    public:
    int val;
    Node* next;
};

Node* getlastnode(Node* head){
    while(head!=NULL&&head->next!=NULL)
    head=head->next;
    return head;
}

Node* getinode(Node* head, int pos){
    for(int i=0;i<pos-2;i++){
        if(head!=NULL)
        head=head->next;
    }
    return head;
}

void createll(Node** head){
    Node* temp;
    
    for(int i=0;i<15;i++){
        temp=new Node();
        temp->val = rand()%10;
        temp->next=NULL;
        if(*head==NULL)
        *head=temp;
        else
        getlastnode(*head)->next=temp;
    }
}

void insertb(Node** head,int val){
    Node* temp= new Node();
    temp->val=val;
    temp->next = *head;
    *head = temp;
}

void inserte(Node** head,int val){
    Node* temp= new Node();
    temp->val=val;
    temp->next = NULL;
    getlastnode(*head)->next=temp;
}

void deletenode(Node** head, int pos){
    Node *prev = getinode(*head,pos);
    if(prev!=NULL)
    prev->next=prev->next->next;
    else
    cout<<" List not that long"<<endl;
}

void insertm(Node**head, int pos,int val){
    Node* temp= new Node(), *prev;
    temp->val=val;
    temp->next = NULL;
    prev=getinode(*head,pos);
    
    if(prev!=NULL){
        temp->next=prev->next;
        prev->next=temp;
    }
    else
    cout<<"List is not that long"<<endl;
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

void reversell(Node** head){
    Node* prev=NULL,*curr=*head,*nextn;
    
    while(curr!=NULL){
        if(curr->next==NULL)
            *head = curr;
        nextn=curr->next;

        curr->next = prev;
        prev= curr;
        curr= nextn;
    }
    
}

void reversell_rec(Node** head,Node* prev,Node* curr){
    if(curr==NULL){
        *head =prev;
        return; 
    }
    reversell_rec(head,curr,curr->next);
    curr->next=prev;
}

void printll(Node* head){
    while(head!=NULL){
        cout<<head->val<<" ";
        head=head->next;
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
    insertm(&head,5,100);
    printll(head);
    deletenode(&head,4);
    printll(head);
    searchll(head,6);
    printll(head);
    sortll(&head); //bubble sort
    printll(head);
    reversell(&head);
    printll(head);
    reversell_rec(&head,NULL,head);
    printll(head);
}