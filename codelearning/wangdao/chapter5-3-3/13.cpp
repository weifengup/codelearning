#include <iostream>
using namespace std;
//找出一个树的两个不同节点的最近公共祖先

#define maxsize 20
typedef struct tnode{
    int info;
    struct tnode *llink,*rlink;
    tnode(int data){
        info=data;
        llink=NULL;
        rlink=NULL;
    }
}tnode;

typedef struct stack{
    tnode *node[maxsize];
    int top=-1;
}stack;

stack getAncestors(tnode *root,tnode *q){
    tnode *p=root;
    tnode *r=NULL;
    stack stack;
    while(p||stack.top!=-1){
        if(p){
            if(p==q)
                return stack;
            stack.node[++stack.top]=p;
            p=p->llink;
        }else{
            p=stack.node[stack.top];
            if(p->rlink&&p->rlink!=r)
            p=p->rlink;
            else{
                stack.node[stack.top--]=NULL;
                r=p;
                p=NULL;
            }
        }
    }
    return stack;

}
void Ancestor(tnode *root,tnode *p,tnode *q,tnode *&r){
    stack s1=getAncestors(root,p);
    stack s2=getAncestors(root,q);
    for(int i=s1.top;i>=0;i--){
        for(int j=s2.top;j>=0;j--)
            if(s1.node[i]==s2.node[j]){
                r=s1.node[i];
                // cout<<r->info;
                return;
            }
    }
}
int main(){
    tnode *root=new tnode(22);
    tnode *n1=new tnode(2);
    tnode *t1l=new tnode(7);
    n1->rlink=t1l;
    tnode *n2=new tnode(3);
    tnode *n3=new tnode(4);
    tnode *n4=new tnode(5);
    root->llink=n1;
    root->rlink=n2;
    n2->llink=n3;
    n2->rlink=n4;
    tnode *ans;
    Ancestor(root,n3,n4,ans);
    cout<<ans->info<<endl;
}