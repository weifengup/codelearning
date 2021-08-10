#include<iostream>
using namespace std;
//找出二叉树中一层拥有的最大节点数
#define maxsize 20
typedef struct tnode{
    int data;
    struct tnode *left,*right;
    tnode(int d){
        data=d;
        left=NULL;
        right=NULL;
    }
}tnode;
typedef struct queue{
    tnode *node[maxsize];
    int front=0,rear=0;
}queue;
int maxwidth(tnode *root){
    if(root==NULL)
        return 0;
    tnode *p=root;
    queue queue;
    if((queue.rear+1)%maxsize!=queue.front)
        queue.node[queue.rear++]=p;
    int num=1,nextnum=0;
    int max=1;
    while(queue.rear%maxsize!=queue.front%maxsize){
        p=queue.node[queue.front++];
        if(p->left!=NULL){
            queue.node[queue.rear++]=p->left;
            nextnum++;
        }
        if(p->right!=NULL){
            queue.node[queue.rear++]=p->right;
            nextnum++;
        }
        num--;
        if(num==0){
            if(max<nextnum)
                max=nextnum;
            num=nextnum;
            nextnum=0;
        }
    }
    return max;
}
int main(){
    tnode *root=new tnode(1);
    tnode *n1=new tnode(2);
    tnode *t1l=new tnode(7);
    n1->left=t1l;
    tnode *t12=new tnode(8);
    n1->right=t12;
    tnode *n2=new tnode(3);
    tnode *n3=new tnode(4);
    tnode *n4=new tnode(5);
    root->left=n1;
    root->right=n2;
    n2->left=n3;
    n2->right=n4;
    cout<<maxwidth(root)<<endl;
}