#include<iostream>
using namespace std;
//讲一个链表分成两个

typedef struct LinkNode{
    int data;
    struct LinkNode *next;
}LinkNode;

void diverse(LinkNode *A,LinkNode *B){
    LinkNode *p=A->next,*q=B;
    while(p!=NULL){
        if(p->next!=NULL){
            q->next=p->next;
            q=q->next;
            p->next=p->next->next;
        }
        p=p->next;
    }
    q->next=NULL;
}
void output(LinkNode *L){
    LinkNode *p=L->next;
    while(p!=NULL){
        cout<<p->data<<endl;
        p=p->next;
    }
}
int main(){
    LinkNode *L=new LinkNode();
    LinkNode *B=new LinkNode();
    LinkNode *n1=new LinkNode();
    n1->data=1;
    L->next=n1;
    LinkNode *n2=new LinkNode();
    n2->data=2;
    n1->next=n2;
    LinkNode *n3=new LinkNode();
    n3->data=3;
    n2->next=n3;
    LinkNode *n4=new LinkNode();
    n4->data=4;
    n3->next=n4;
    LinkNode *n5=new LinkNode();
    n5->data=5;
    n4->next=n5;
    LinkNode *n6=new LinkNode();
    n6->data=6;
    n5->next=n6;
    diverse(L,B);
    output(L);
    cout<<"======="<<endl;
    output(B);
}