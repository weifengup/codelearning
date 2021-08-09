#include<iostream>
using namespace std;
//使带头节点的链表递增有序

typedef struct LinkNode{
    int data;
    struct LinkNode *next;
}LinkNode;

void sort(LinkNode *L){
    if(L->next==NULL||L->next->next==NULL)
        return;
    LinkNode *p=L->next;
    LinkNode *rear=p->next;
    p->next=NULL;
    LinkNode *pre,*q;
    while(rear!=NULL){
        pre=L;
        p=L->next;
        while(p!=NULL){
            if(rear->data<p->data)
            break;
            pre=p;
            p=p->next;
        }
        q=rear->next;
        pre->next=rear;
        rear->next=p;
        rear=q;
    }
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
    LinkNode *n1=new LinkNode();
    n1->data=5;
    L->next=n1;
    LinkNode *n2=new LinkNode();
    n2->data=3;
    n1->next=n2;
    LinkNode *n3=new LinkNode();
    n3->data=4;
    n2->next=n3;
    LinkNode *n4=new LinkNode();
    n4->data=1;
    n3->next=n4;
    LinkNode *n5=new LinkNode();
    n5->data=2;
    n4->next=n5;
    sort(L);
    output(L);
}