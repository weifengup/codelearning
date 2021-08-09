#include<iostream>
using namespace std;
#include <stack>
//非递归版的中序遍历
typedef struct tnode{
    int data;
    struct tnode *left,*right;
    tnode(int d){
        data=d;
        left=NULL;
        right=NULL;
    }
}tnode;
void mid_order(tnode *root){
    tnode *p=root;
    stack<tnode*>stack;
    while(p||!stack.empty()){
        if(p){
            stack.push(p);
            p=p->left;
        }else{
            p=stack.top();
            stack.pop();
            cout<<p->data<<endl;
            p=p->right;
        }
    }
}
int main(){
    tnode *root=new tnode(1);
    tnode *n1=new tnode(2);
    tnode *t1l=new tnode(7);
    n1->right=t1l;
    tnode *n2=new tnode(3);
    tnode *n3=new tnode(4);
    tnode *n4=new tnode(5);
    root->left=n1;
    root->right=n2;
    n2->left=n3;
    n2->right=n4;
    mid_order(root);
}