#include<iostream>
using namespace std;
//计算所有根到叶节点过程的所有节点的weight和的总和
typedef struct tnode{
    int weight;
    struct tnode *left,*right;
    tnode(int data){
        weight=data;
        left=NULL;
        right=NULL;
    }
}tnode;
void getLength(tnode *root,int value,int &sum){
    if(root==NULL)
        return;
    value+=root->weight;
    if(root->left==NULL&&root->right==NULL)
        sum+=value;
    getLength(root->left,value,sum);
    getLength(root->right,value,sum);
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
    int WPL=0;
    getLength(root,0,WPL);
    cout<<WPL<<endl;
}