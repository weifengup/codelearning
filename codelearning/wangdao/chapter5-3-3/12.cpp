#include<iostream>
using namespace std;
#include<stack>
//打印值为x的节点的所有祖先（即打印根节点到x的路径）
//要找出根节点到某一结点的路径上的所有节点，可以利用非递归的后序遍历
//当遍历到x时，栈中的元素即为路径上的元素
typedef struct tnode{
    int data;
    int time;
    struct tnode *left,*right;
    tnode(int d){
        data=d;
        time=0;
        left=NULL;
        right=NULL;
    }
    tnode(){
        time=0;
        left=NULL;
        right=NULL;
    }
}tnode;

void path(tnode *root,int x){
    tnode *p=root;
    stack<tnode*> stack;
    stack.push(p);
    while(!stack.empty()){
        p=stack.top();
        stack.pop();
        if(p->data==x){
            while(!stack.empty()){
                p=stack.top();
                stack.pop();
                cout<<p->data<<endl;
            }
            return;
        }
        if(p->time==0){
            stack.push(p);
            if(p->left!=NULL)
                stack.push(p->left);
        }
        else if(p->time==1){
            stack.push(p);
            if(p->right!=NULL)
                stack.push(p->right);
        }
        p->time+=1;
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
    path(root,3);
}