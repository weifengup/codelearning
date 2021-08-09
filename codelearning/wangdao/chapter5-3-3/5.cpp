#include<iostream>
using namespace std;
#include<stack>
#include<queue>
//计算二叉树的高度
typedef struct tnode{
    int data;
    struct tnode *left,*right;
    tnode(int d){
        data=d;
        left=NULL;
        right=NULL;
    }
}tnode;

//利用非递归版的深度遍历
int getLength(tnode *root){
    tnode *p=root;
    stack<tnode*>stack;
    int length=0,maxlength=-1,sub=0;
    while(p||!stack.empty()){
        if(p){
            stack.push(p);
            p=p->left;
            length++;
        }else{
            p=stack.top();
            stack.pop();
            if(p->right==NULL){
                if(length>maxlength)
                    maxlength=length;
                length--;
                length-=sub;
                sub=0;
            }else{
                sub++;
            }
            p=p->right;
        }
    }
    return maxlength;
}
//递归版
int getLength2(tnode *root){
    if(root==NULL)
        return 0;
    int ldep=getLength2(root->left);
    int rdep=getLength2(root->right);
    if(ldep>rdep)
        return ldep+1;
    else return rdep+1;
}
//层次遍历版
int getLength3(tnode* root){
    if(root==NULL)
        return 0;
    int dep=0,level=1,nextlevel=0;
    queue<tnode*>queue;
    tnode *p=root;
    queue.push(p);
    while(!queue.empty()){
        p=queue.front();
        queue.pop();
        level--;
        if(p->left!=NULL){
            nextlevel++;
            queue.push(p->left);
        }
        if(p->right!=NULL){
            nextlevel++;
            queue.push(p->right);
        }
        if(level==0){
            dep++;
            level=nextlevel;
            nextlevel=0;
        }
    }
    return dep;
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
    n2->right=n3;
    n3->left=n4;
    tnode *n5=new tnode(6);
    t1l->right=n5;
    tnode *n6=new tnode(7);
    n4->right=n6;
    cout<<"深度遍历递归"<<getLength2(root)<<endl;
    cout<<"深度遍历非递归"<<getLength(root)<<endl;
    cout<<"层次遍历非递归"<<getLength3(root)<<endl;
}