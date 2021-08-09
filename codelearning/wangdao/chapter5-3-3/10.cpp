#include<iostream>
using namespace std;
//找到前序遍历的第k个节点的值
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
int pre_order(tnode *root,int &i,int k){
    if(root==NULL)
        return 999;
    if(i==k)
        return root->data;
    i++;
    int temp=pre_order(root->left,i,k);
    if(temp!=999)
        return temp;
    temp=pre_order(root->right,i,k);
    return temp;
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

    int i=1;
    cout<<pre_order(root,i,2);
}