#include<iostream>
using namespace std;
//将二叉树所有左右子树交换位置
typedef struct tnode{
    int data;
    struct tnode *left,*right;
    tnode(int d){
        data=d;
        left=NULL;
        right=NULL;
    }
}tnode;
void output(tnode *root){
    if(root==NULL)
        return ;
    cout<<root->data<<endl;
    output(root->left);
    output(root->right);
}
void change(tnode *root){
    if(root){
        tnode *p=root->left;
        root->left=root->right;
        root->right=p;
        change(root->left);
        change(root->right);
    }
}
void swap(tnode *root){
    if(root){
        swap(root->left);
        swap(root->right);
        tnode *p=root->left;
        root->left=root->right;
        root->right=p;
    }
}
int main(){
    tnode *root=new tnode(0);
    tnode *t1=new tnode(1);
    tnode *t2=new tnode(2);
    root->left=t1;
    root->right=t2;
    tnode *t3=new tnode(3);
    tnode *t4=new tnode(4);
    t1->left=t3;
    t1->right=t4;
    tnode *t5=new tnode(5);
    tnode *t6=new tnode(6);
    t2->left=t5;
    t2->right=t6;
    output(root);
    swap(root);
    //change(root);
    cout<<"========"<<endl;
    output(root);
}