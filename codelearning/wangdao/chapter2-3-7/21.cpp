#include <iostream>
using namespace std;
//查找链表中倒数第k个位置上的节点

typedef struct LNode{
    int data;
    struct LNode *next;
}LinkNode;

int Locate(LinkNode *L,int k){
    int count=0;
    LinkNode *p=L->next,*q=L->next;
    while(p){
        if(count<k) count++;
        else q=q->next;
        p=p->next;
    }
    if(count<k)
        return 0;
    cout<<q->data<<endl;
    return 1;
}
int main(){
    LinkNode *L=new LinkNode();
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
    Locate(L,2);
}