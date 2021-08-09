#include<iostream>
using namespace std;
//将两个递增有序的链表，合并为一个递减的链表

typedef struct LinkNode{
    int data;
    struct LinkNode *next;
}LinkNode;

LinkNode * merge(LinkNode *A,LinkNode *B){
    LinkNode *head=NULL,*p=A,*q=B,*temp;
    while(p!=NULL&&q!=NULL){
        if(p->data<=q->data){
            temp=p;
            p=p->next;
        }else{
            temp=q;
            q=q->next;
        }
        temp->next=head;
        head=temp;
    }
    while(p!=NULL){
        temp=p;
        p=p->next;
        temp->next=head;
        head=temp;
    }
    while(q!=NULL){
        temp=q;
        q=q->next;
        temp->next=head;
        head=temp;
    }
    return head;
}
void output(LinkNode *L){
    LinkNode *p=L;
    while(p!=NULL){
        cout<<p->data<<endl;
        p=p->next;
    }
}
int main(){
    LinkNode *A=new LinkNode();
    A->data=1;
    LinkNode *B=new LinkNode();
    B->data=2;
    LinkNode *n1=new LinkNode();
    n1->data=3;
    A->next=n1;
    LinkNode *n2=new LinkNode();
    n2->data=4;
    B->next=n2;
    LinkNode *n3=new LinkNode();
    n3->data=5;
    n1->next=n3;
    LinkNode *n4=new LinkNode();
    n4->data=6;
    n2->next=n4;
    output(A);
    cout<<"======="<<endl;
    output(B);
    cout<<"======="<<endl;
    LinkNode *head=merge(A,B);
    output(head);
}