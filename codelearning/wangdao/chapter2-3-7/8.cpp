#include<iostream>
using namespace std;
//找出两个单链表的公共节点
typedef struct LinkNode{
    int data;
    struct LinkNode *next;
}LinkNode;
int getLength(LinkNode *L1){
    LinkNode *p=L1;
    int len=0;
    while(p!=NULL){
        len++;
        p=p->next;
    }
    return len;
}
//右对齐然后，从统一出发点开始，找是否有相等的节点
LinkNode * findCommon(LinkNode *L1,LinkNode *L2){
    //dist记录长度之差
    int len1=getLength(L1),len2=getLength(L2),dist;
    LinkNode *longnode,*shortnode;
    if(len1>len2){
        dist=len1-len2;
        longnode=L1;
        shortnode=L2;
    }else{
        dist=len2-len1;
        longnode=L2;
        shortnode=L1;
    }
    while(dist--)
        longnode=longnode->next;
    while(shortnode!=NULL){
        if(longnode==shortnode)
            return shortnode;
        else{
            shortnode=shortnode->next;
            longnode=longnode->next;
        }
    }
    return NULL;
}
//test
void output(LinkNode *L){
    LinkNode *p=L;
    while(p!=NULL){
        cout<<p->data<<endl;
        p=p->next;
    }
}
int main(){
    LinkNode *L=new LinkNode();
    L->data=7;
    LinkNode *L2=new LinkNode();
    L2->data=13;
    LinkNode *n1=new LinkNode();
    n1->data=5;
    L->next=n1;
    LinkNode *n2=new LinkNode();
    n2->data=3;
    n1->next=n2;
    LinkNode *n3=new LinkNode();
    n3->data=4;
    L2->next=n3;
    n2->next=n3;
    LinkNode *n4=new LinkNode();
    n4->data=1;
    n3->next=n4;
    LinkNode *n5=new LinkNode();
    n5->data=2;
    n4->next=n5;
    output(L);
    cout<<"============";
    output(L2);
    cout<<"============";
    cout<<findCommon(L,L2)->data<<endl;
}