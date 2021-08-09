#include<iostream>
using namespace std;
#include<stack>
//非递归版前序遍历
typedef struct tnode{
    int data;
    struct tnode *left,*right;
    tnode(int d){
        data=d;
        left=NULL;
        right=NULL;
    }
}tnode;
void pre_order(tnode *root){
    stack<tnode*> stack;
    tnode *p=root;
    while(p||!stack.empty()){
        if(p){
            cout<<p->data<<endl;
            stack.push(p);
            p=p->left;
        }else{
            p=stack.top();
            stack.pop();
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
    pre_order(root);
}