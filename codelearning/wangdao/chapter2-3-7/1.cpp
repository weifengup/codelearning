#include<iostream>
using namespace std;
//利用递归，删除不带头节点的单链表中所有值为x的节点

typedef struct LinkNode{
    char data;
    struct LinkNode *next;
}LinkNode;

void delete_x(LinkNode* &L,char x){
    if(L==NULL)
        return;
    LinkNode *p;
    if(L->data==x){
        p=L;
        L=L->next;
        free(p);
        delete_x(L,x);
    }else
        delete_x(L->next,x);
}
void output(LinkNode *head){
    LinkNode *p=head;
    while(p!=NULL){
        cout<<p->data<<endl;
        p=p->next;
    }
}
int main(){
    LinkNode *head=new LinkNode();
    head->data='x';
    LinkNode *n1=new LinkNode();
    n1->data='a';
    head->next=n1;
    LinkNode *n2=new LinkNode();
    n2->data='x';
    n1->next=n2;
    delete_x(head,'a');
    output(head);
}