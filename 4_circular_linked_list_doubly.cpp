#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* prev;
    Node* next;
};

void traverse_dcll(Node* head){
    if(head==NULL){
        cout<<"EMPTY LIST"<<endl;
        return;
    }

    Node* iterator=head;
    while(iterator->next!=head){
        cout<<iterator->data<<" -> ";
        iterator=iterator->next;}
    cout<<iterator->data<<"  "<<endl;
    return;
}

void search_dcll(Node* head,int val){
    if(head==NULL){
        cout<<"NODE NOT FOUND! (EMPTY LIST)"<<endl;
        return;
    }
    int i=0;
    Node* iterator=head;
    while(iterator->next!=head && iterator->data!=val){
        i++;
        iterator=iterator->next;}
    if(iterator->data==val){
        i++;
        cout<<"NODE FOUND! (given data found in node "<<i<<")"<<endl;
    }
    else{
        cout<<"NODE NOT FOUND!"<<endl;
    }
    return;
}

Node* insert_in_beg_dcll(Node* head,int val){
    Node* newnode=new Node();
    newnode->data=val;
    if(head==NULL){
        newnode->next=newnode;
        newnode->prev=newnode;
        head=newnode;
        return head;
    }
    Node* last=head->prev;
    newnode->next=head;
    newnode->prev=last;
    head->prev=newnode; 
    last->next=newnode;  
    head=newnode;
    return head;
}
Node* insert_at_end_dcll(Node* head,int val){
    Node* newnode=new Node();
    newnode->data=val;
    if(head==NULL){
        newnode->prev=newnode->next=newnode;
        head=newnode;
        return head;
    }

    Node* last=head->prev;
    last->next=newnode;
    newnode->prev=last;
    newnode->next=head;
    head->prev=newnode;
    return head;
}
Node* insert_after_specific_val_dcll(Node* head,int val,int sval){
    Node* newnode=new Node();
    newnode->data=val;
    if(head==NULL){
        newnode->prev=newnode->next=newnode;
        head=newnode;
        return head;
    }
    
    Node* iterator=head;
    while(iterator->next!=head && iterator->data!=sval){
        iterator=iterator->next;
    }
    if(iterator->data==sval){
        newnode->next=iterator->next;
        newnode->prev=iterator;
        (iterator->next)->prev=newnode;
        iterator->next=newnode;
        return head;
    }
    else{
        cout<<"NODE WITH GIVEN VALUE NOT FOUND!"<<endl;
        delete newnode;
        return head;
    }
}

Node* delete_from_beg_dcll(Node* head){
    if(head==NULL){
        cout<<"ERROR!-(empty list)"<<endl;
    }
    else if(head->next==head){
        delete head;
        head==NULL;
    }
    else{
        Node* last=head->prev;
        last->next=head->next;
        (head->next)->prev=last;
        delete head;
        head=head->next;
    }
    return head;
}


Node* delete_from_end_dcll(Node* head){
    if(head==NULL){
        cout<<"ERROR!-(empty list)"<<endl;
    }
    else if(head->next==head){
        delete head;
        head==NULL;
    }
    else{
        Node* last=head->prev;
        (last->prev)->next=head;
        head->prev=last->prev;
        delete last;
    }
    return head;
}

Node* delete_after_specific_value_dcll(Node* head,int sval){
    if(head==NULL){
        cout<<"ERROR!-(empty list)"<<endl;
        return head;
    }
    else if(head->next==head && head->data==sval){
        delete head;
        head==NULL;
        return head;
    }
    
    Node* iterator=head;
    while(iterator->next!=head && iterator->data!=sval){
        iterator=iterator->next;
    }
    if(iterator->data==sval){
        (iterator->prev)->next=iterator->next;
        (iterator->next)->prev=iterator->prev;
        delete iterator;
        return head;
    }
    else{
        cout<<"NODE WITH GIVEN VALUE NOT FOUND!"<<endl;
        return head;
    }
}

int main(){
    Node* head=NULL;
    //search_dcll(head,40);

    Node* a=new Node();
    Node* b=new Node();

    head=a;

    a->data=10;
    a->next=b;
    a->prev=b;

    b->data=20;
    b->next=head;
    b->prev=a;
    traverse_dcll(head);
    search_dcll(head,20);
    head=insert_in_beg_dcll(head,40);
    traverse_dcll(head);
    head=insert_at_end_dcll(head,50);
    traverse_dcll(head);
    head=insert_after_specific_val_dcll(head,60,20);
    traverse_dcll(head);
    head=delete_from_beg_dcll(head);
    traverse_dcll(head);
    head=delete_from_end_dcll(head);
    traverse_dcll(head);
    head=delete_after_specific_value_dcll(head,20);
    traverse_dcll(head);

}