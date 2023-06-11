#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
};
Node* insert_at_beg_scll(Node* head,int num){
    Node* temp=new Node();
    temp->data=num;
    if(head==NULL){
        temp->next=temp;
    }
    else{
        temp->next=head;
        Node* last=head;
        while(last->next!=head){
            last=last->next;
        }
        last->next=temp;}
    head=temp; 
    return head;
}
Node* insert_after_specific_val_scll(Node* head,int num,int val){
    Node* temp=new Node();
    temp->data=num;
    if(head==NULL){
        temp->next=temp;
        head=temp;
    }
    else{
        Node* target=head;
        while(target->next!=head && target->data!=val){
            target=target->next;
        }
        if(target->data==val){
            temp->next=target->next;
            target->next=temp;
        }
        else{
            cout<<"Value not in linked list"<<endl;
        }
    }
    return head;
}
Node* insert_at_end_scll(Node* head,int num){
    Node* temp=new Node();
    temp->data=num;
    if(head==NULL){
        head=temp;
        temp->next=temp;
    }
    else{
        temp->next=head;
        Node* last=new Node();
        last=head;
        while(last->next != head){
            last=last->next;
        }
        last->next=temp;
    }
    return head;
}
Node* delete_from_end_scll(Node* head){
    if(head==NULL){
        cout<<"ERROR!-(empty list)"<<endl;
    }
    else if(head->next==head){
        head==NULL;
    }
    else{
        Node* sec_last=head;
        Node* target=head;
        while(target->next!=head){
            sec_last=target;
            target=target->next;
        }
        sec_last->next=head;
        delete target;
    }
    return head;
}
Node* delete_from_beg_scll(Node* head){
    if(head==NULL){
        cout<<"ERROR!-(empty linked list)"<<endl;
        return head;
    }
    else if(head->next==head){
        delete head;
        head=NULL;
        return head;
    }
    else{ 
        Node* last=head;
        Node* target=head;
        int i=0;
        while(last->next!=head){
            last=last->next;
        }
        last->next=target->next;
        head=last->next;
        delete target;
        return head;
        }
    
}
Node* delete_a_particular_value_scll(Node* head,int val){
    if(head==NULL){
        cout<<"ERROR! (empty list)"<<endl;
    }
    else if(head->next==head && head->data==val){
        delete head;
        head=NULL;
    }
    else{
        Node* pre_target=head;
        Node* target=head;
        while(target->next!=head && target->data !=val){
            pre_target=target;
            target=target->next;}

        if (target->data==val){
            pre_target->next=target->next;
            delete target;
            }

        else{
            cout<<"Node not found!"<<endl;}

    }
    return head;
}
void traverse_scll(Node *head){
    if(head==NULL){
        cout<<"Empty List"<<endl;
        return;
    }
    else{
        Node* temp=head;
        while(temp->next != head){
            cout<<" "<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<" "<<temp->data<<" ";
        cout<<endl;
        return;
    }
}
int main() {
    class Node* head=NULL;
    class Node* one= NULL;
    class Node* two= NULL;
    one=new Node();
    two=new Node();
    
    head= one;
    
    one->data=10;
    one->next=two;

    two->data=20;
    two->next=head;
    
    traverse_scll(head);
    head=insert_at_end_scll(head,30);
    traverse_scll(head);
    head=insert_at_end_scll(head,40);
    traverse_scll(head);
    head=insert_after_specific_val_scll(head,50,20);
    traverse_scll(head);
    head=delete_a_particular_value_scll(head,78);
    traverse_scll(head);
    head=delete_from_end_scll(head);
    traverse_scll(head);
    head=delete_from_beg_scll(head);
    traverse_scll(head);
    head=insert_at_beg_scll(head,70);
    traverse_scll(head);


return 0;
}