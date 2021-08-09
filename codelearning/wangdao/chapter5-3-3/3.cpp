#include<iostream>
using namespace std;
#include<stack>
//利用非递归的方式，完成二叉树的后序遍历

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
void back_order(tnode *root){
    tnode *p=root;
    stack<tnode*> s;
    s.push(p);
    while(!s.empty()){
        p=s.top();
        s.pop();
        if(p->time==0){
            s.push(p);
            if(p->left!=NULL)
                s.push(p->left);
        }
        else if(p->time==1){
            s.push(p);
            if(p->right!=NULL)
                s.push(p->right);
        }
        else if(p->time==2){
            cout<<p->data<<endl;
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
    back_order(root);
}