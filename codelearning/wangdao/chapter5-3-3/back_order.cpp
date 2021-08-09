#include<iostream>
using namespace std;
#include<stack>
//非递归版的后序遍历，3.cpp中是通过在节点中增加了一个num来记录是否已被访问，而本算法利用一个辅助指针指向最近访问的节点

typedef struct tnode{
    int data;
    struct tnode *left,*right;
    tnode(int d){
        data=d;
        left=NULL;
        right=NULL;
    }
}tnode;

void back_order(tnode *root){
    tnode *p=root;
    tnode *r=NULL;
    stack<tnode*> stack;
    while(p||!stack.empty()){
        if(p){
            stack.push(p);
            p=p->left;
        }else{
            p=stack.top();
            //如果p有右子树，且未被访问过，则不出栈，处理右子树
            if(p->right&&p->right!=r){
                p=p->right;
            }else{
                stack.pop();
                cout<<p->data<<endl;
                //由于后序遍历是从下向上输出的，因此一个节点访问完，紧接着要访问的是他的祖先，令r=p,即标志出最近访问过p，那么p不会再被访问
                r=p;
                //每次出栈一个节点相当于遍历完以该节点为根的子树，置为NULL
                p=NULL;
            }
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
    back_order(root);
}