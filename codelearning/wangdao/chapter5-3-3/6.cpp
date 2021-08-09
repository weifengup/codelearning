#include<iostream>
using namespace std;
//根据先序遍历序列和中序遍历序列确定二叉树

typedef struct tnode{
    int data;
    struct tnode *left,*right;
    tnode(int d){
        data=d;
        left=NULL;
        right=NULL;
    }
}tnode;
tnode * create_node(int A[],int B[],int a,int b,int c,int d){
    if(a>b||c>d)
        return NULL;
    tnode *p=new tnode(A[a]);
    int index=c;
    for(;index<=d;index++)
        if(B[index]==A[a])
            break;
    int len=index-c;
    p->left=create_node(A,B,a+1,a+len,c,index-1);
    p->right=create_node(A,B,a+len+1,b,index+1,d);
    return p;
}
void output(tnode *root){
    if(root==NULL)
        return ;
    cout<<root->data<<endl;
    output(root->left);
    output(root->right);
}
int main(){
    int A[]={1,2,4,8,5,3,6,7,9};
    int B[]={8,4,2,5,1,6,3,7,9};
    tnode *root=create_node(A,B,0,8,0,8);
    output(root);
}